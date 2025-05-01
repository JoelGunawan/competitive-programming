set -e
g++ h.cpp -o main
g++ gen.cpp -o gen
g++ brute.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > input
    ./main < input > out
    ./brute < input > ans
    diff out ans > /dev/null || break
    echo "AC: "  $i
done
echo "WA:"
cat input
echo "Out:"
cat out
echo "Ans:"
cat ans