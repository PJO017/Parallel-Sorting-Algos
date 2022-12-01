#!/bin/bash
echo "Compiling..."

g++ createRandom.cpp -o createRandom
g++ createReverseSorted.cpp -o createReverseSorted

mkdir ../data/Random
mkdir ../data/ReverseSorted

sizes=(25000 50000 75000 100000 250000 500000 750000 1000000)

echo ""
echo "Generating Random Data..."
for i in "${sizes[@]}"; do
  time=$(./createRandom "$i")
  sleep 1
done
echo "done."

echo ""
echo "Generating Reverse Sorted Data..."
for i in "${sizes[@]}"; do
  time=$(./createReverseSorted "$i")
done
echo "done."

rm createRandom
rm createReverseSorted
