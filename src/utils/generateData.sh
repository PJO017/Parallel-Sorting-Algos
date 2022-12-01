#!/bin/bash
echo "Compiling..."

g++ createRandom.cpp -o createRandom

sizes=(25000 50000 75000 100000 250000 500000 750000 1000000)

echo ""
echo "Generating Random Data..."
for i in "${sizes[@]}"; do
  time=$(./createRandom "$i")
  sleep 1
done
echo "done."

rm createRandom
