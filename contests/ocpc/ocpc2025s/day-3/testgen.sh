g++-14 -O2 i.cpp -o main
g++-14 -O2 brute.cpp -o brute
g++-14 -O2 gen.cpp -o gen
for((i = 1; ; i++)); do
  ./gen $i > inp
  ./brute < inp > ans
  ./main < inp > out
  diff out ans > /dev/null || break
  echo "AC: " $i
done 
echo "WA: "
cat inp 
echo "Out: "
cat out 
echo "Ans: "
cat ans 