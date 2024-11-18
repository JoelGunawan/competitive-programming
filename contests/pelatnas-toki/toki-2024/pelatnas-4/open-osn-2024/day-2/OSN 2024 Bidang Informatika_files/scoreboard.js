var currentProblemCount = 0;

function fetchScoreboard(contestJid) {
  $.get(config.serverUrl + "?contestJid=" + contestJid, function (data) {
    refreshScoreboard(data);

    // setTimeout(function () {
    //   fetchScoreboard(contestJid);
    // }, config.refreshIntervalInMs);
  });
}

function refreshScoreboardProblems(problemAliases) {
  $(".col-problem").remove();

  for (var i = 0; i < problemAliases.length; i++) {
    var alias = problemAliases[i];
    var header = $("<th>");
    header.prop("class", "col-score col-problem");
    header.html(alias);
    $("#headers").append(header);
  }
}

function calculateScoreColor(score, problemCount) {
  if (score == null) {
    return "#eee";
  }
  var hue = (score * 120.0) / (100.0 * problemCount);
  return "hsl(" + hue.toString() + ", 80%, 60%)";
}

function createRow(entry) {
  var contestant = config.contestants[entry.contestantJid];
  var tr = $("<tr>");
  tr.append($("<td>").html(entry.rank));
  tr.append($("<td>").prop("class", "col-username").html(contestant.username));
  tr.append($("<td>").html(contestant.name));
  tr.append($("<td>").html(contestant.school));
  tr.append($("<td>").html(contestant.province));
  tr.append(
    $("<td>")
      .html(entry["totalScores"])
      .css({
        "font-weight": "bold",
        "background-color": calculateScoreColor(
          entry["totalScores"],
          currentProblemCount
        ),
      })
  );

  for (var j = 0; j < entry["scores"].length; j++) {
    var score = entry["scores"][j];
    tr.append(
      $("<td>")
        .html(score)
        .css({ "background-color": calculateScoreColor(score, 1) })
    );
  }

  return tr;
}

function refreshScoreboardEntries(entries) {
  $("#entries").empty();
  for (var i = 0; i < entries.length; i++) {
    $("#entries").append(createRow(entries[i]));
  }
}

function updateTimestamp(lastUpdateTime) {
  $("#lastUpdateTime").html(lastUpdateTime);
}

function updateProgressBar() {
  var now = +new Date();
  var progress = now - config.contestStartTimestampInMs;
  var percentage = (progress * 100.0) / config.contestDurationInMs;
  $("#progress-bar").css({ width: percentage + "%" });
}

function refreshScoreboard(data) {
  var scoreboard = data.scoreboard;
  var problemAliases = scoreboard.state.problemAliases;
  var entries = scoreboard.content.entries;

  if (currentProblemCount == 0) {
    refreshScoreboardProblems(problemAliases);
  }
  currentProblemCount = problemAliases.length;

  refreshScoreboardEntries(entries);

  updateTimestamp(new Date(data.updatedTime));
  updateProgressBar();
}
