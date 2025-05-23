// Taken from
// https://github.com/Kattis/problemtools/blob/develop/examples/guess/output_validators/guess_validator/validate.h
// (under MIT License)
// with modification by ICPC Japan regional team

/* Utility functions for writing output validators for the Kattis
 * problem format.
 *
 * The primary functions and variables available are the following.
 * In many cases, the only functions needed are "init_io",
 * "wrong_answer", and "accept".
 *
 * - init_io(argc, argv):
 *        initialization
 *
 * - judge_in, judge_ans:
 *        std::istream objects for judge input file, judge answer file
 *
 * - author_out:
 *        submission's output. Use author_out.get() method to retrieve the input
 *
 * - accept():
 *        exit and give Accepted!
 *        When extra output is found, the verdict will be modified to wrong answer
 *
 * - accept_with_score(double score):
 *        exit with Accepted and give a score (for scoring problems)
 *
 * - judge_message(std::string msg, ...):
 *        printf-style function for emitting a judge message (a
 *        message that gets displayed to a privileged user with access
 *        to secret data etc).
 *
 * - wrong_answer(std::string msg, ...):
 *        printf-style function for exiting and giving Wrong Answer,
 *        and emitting a judge message (which would typically explain
 *        the cause of the Wrong Answer)
 *
 * - judge_error(std::string msg, ...):
 *        printf-style function for exiting and giving Judge Error,
 *        and emitting a judge message (which would typically explain
 *        the cause of the Judge Error)
 *
 * - author_message(std::string msg, ...):
 *        printf-style function for emitting an author message (a
 *        message that gets displayed to the author of the
 *        submission).  (Use with caution, and be careful not to let
 *        it leak information!)
 *
 */
#pragma once

#include <sys/stat.h>
#include <cstdio>
#include <cassert>
#include <cstdarg>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <csignal>

typedef void (*feedback_function)(const std::string &, ...);

const int EXITCODE_AC = 42;
const int EXITCODE_WA = 43;
const std::string FILENAME_AUTHOR_MESSAGE = "teammessage.txt";
const std::string FILENAME_JUDGE_MESSAGE = "judgemessage.txt";
const std::string FILENAME_JUDGE_ERROR = "judgeerror.txt";
const std::string FILENAME_SCORE = "score.txt";

#define USAGE "%s: judge_in judge_ans feedback_dir < author_out\n"

std::ifstream judge_in, judge_ans;
// std::istream author_out(std::cin.rdbuf());

bool verbose = std::getenv("INTERACTOR_VERBOSE") != nullptr;

struct AuthorOutput {
  std::stringstream ss;

  template<typename T>
  bool get(T& t) {
    while (1) {
      std::string token;
      if (ss >> token) {
        std::stringstream ss_tk(token);
        T ret;
        if ((ss_tk >> ret) && ss_tk.eof()) {
          t = ret;
          return true;
        } else {
          // failed to parse
          return false;
        }
      }

      const int LIMIT = 4 * 1000 * 1000;  // 4MB per line
      std::string line;
      while (line.size() <= LIMIT) {
        char ch;
        if (std::cin.get(ch)) {
          if (ch == '\n' || ch == '\0') break;
          else line.push_back(ch);
        } else {
          return false;
        }
      }

      ss = std::stringstream(line);
      if (verbose) {
        std::cerr << "AUTHOR:" << line << std::endl;
      }
    }
  }
};

AuthorOutput author_out;

#define jprintln(fmt, args...) \
{ \
  printf(fmt, ##args); \
  puts(""); \
  fflush(stdout); \
  if (verbose) { \
    fprintf(stderr, "JUDGE: "); \
    fprintf(stderr, fmt, ##args); \
    fprintf(stderr, "\n"); \
    fflush(stderr); \
  } \
}

char *feedbackdir = NULL;

void vreport_feedback(const std::string &category,
                      const std::string &msg,
                      va_list pvar) {
    std::ostringstream fname;
    if (feedbackdir)
        fname << feedbackdir << '/';
    fname << category;
    FILE *f = fopen(fname.str().c_str(), "a");
    assert(f);
    int size = 20000;
    char dumps[size];
    vsnprintf(dumps, size, msg.c_str(), pvar);
    fprintf(f, "%s", dumps);
    if (verbose) {
      fprintf(stderr, "JUDGE(FEEDBACK)>>>%s", dumps);
    }
    fclose(f);
}

void report_feedback(const std::string &category, const std::string &msg, ...) {
    va_list pvar;
    va_start(pvar, msg);
    vreport_feedback(category, msg, pvar);
}

void author_message(const std::string &msg, ...) {
    va_list pvar;
    va_start(pvar, msg);
    vreport_feedback(FILENAME_AUTHOR_MESSAGE, msg, pvar);
}

void judge_message(const std::string &msg, ...) {
    va_list pvar;
    va_start(pvar, msg);
    vreport_feedback(FILENAME_JUDGE_MESSAGE, msg, pvar);
}

void judge_error(const std::string &msg, ...) {
    va_list pvar;
    va_start(pvar, msg);
    vreport_feedback(FILENAME_JUDGE_ERROR, msg, pvar);
    assert(0);
}

void wrong_answer(const std::string &msg, ...) {
    va_list pvar;
    va_start(pvar, msg);
    vreport_feedback(FILENAME_JUDGE_MESSAGE, msg, pvar);

    exit(EXITCODE_WA);
}

void accept() {
    fclose(stdout);
    std::string trash;
    if (author_out.get(trash)) {
      // when trash is found, it is converted to wrong answer
      wrong_answer("Trailing output: '%s'\n", trash.c_str());
    }
    exit(EXITCODE_AC);
}

void accept_with_score(double scorevalue) {
    report_feedback(FILENAME_SCORE, "%.9le", scorevalue);
    exit(EXITCODE_AC);
}


bool is_directory(const char *path) {
    struct stat entry;
    return stat(path, &entry) == 0 && S_ISDIR(entry.st_mode);
}

void init_io(int argc, char **argv) {
    if(argc < 4) {
        fprintf(stderr, USAGE, argv[0]);
        judge_error("Usage: %s judgein judgeans feedbackdir [opts] < userout", argv[0]);
    }
    if (std::getenv("USING_HELPER")) {
      // When only using a helper, ignore sigpipe error
      signal(SIGPIPE, SIG_IGN);
    }

    // Set up feedbackdir first, as that allows us to produce feedback
    // files for errors in the other parameters.
    if (!is_directory(argv[3])) {
        judge_error("%s: %s is not a directory\n", argv[0], argv[3]);
    }
    feedbackdir = argv[3];

    judge_in.open(argv[1], std::ios_base::in);
    if (judge_in.fail()) {
        judge_error("%s: failed to open %s\n", argv[0], argv[1]);
    }

    judge_ans.open(argv[2], std::ios_base::in);
    if (judge_ans.fail()) {
        judge_error("%s: failed to open %s\n", argv[0], argv[2]);
    }
}
