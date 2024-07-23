set -e
g++-13 a.cpp -o a
g++-13 gen.cpp -o gen
g++-13 brute.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > input
    ./a < input > out
    ./brute < input > ans
    diff out ans > /dev/null || break
done
echo "WA:"
cat input
echo "Out:"
cat out
echo "Ans:"
cat ansset -e
g++-13 a.cpp -o a
g++-13 gen.cpp -o gen
g++-13 brute.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > input
    ./a < input > out
    ./brute < input > ans
    diff out ans > /dev/null || break
done
echo "WA:"
cat input
echo "Out:"
cat out
echo "Ans:"
cat ans