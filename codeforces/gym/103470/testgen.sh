set -e
g++-13 d.cpp -o main
g++-13 gen.cpp -o gen
g++-13 brute.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > input
    ./main < input > out
    ./brute < input > ans
    diff out ans > /dev/null || break
done
echo "WA:"
cat input
echo "Out:"
cat out
echo "Ans:"
cat ans