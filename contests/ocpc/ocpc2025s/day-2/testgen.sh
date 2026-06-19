set -e
g++-14 d.cpp -o main
g++-14 gen.cpp -o gen
g++-14 brute.cpp -o brute
for((i = 1; ; ++i)); do
  ./gen $i > file.in
  ./main < file.in > out
  ./brute < file.in > ans
  diff out ans > /dev/null || break
  echo "AC: " $i
done
echo "WA: "
cat file.in
echo "Out: "
cat out 
echo "Ans: "
cat ans