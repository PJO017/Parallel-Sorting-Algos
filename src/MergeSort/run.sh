#!/bin/bash
g++ seq_mergesort.cpp -o seq_mergesort
g++ par_mergesort.cpp -fopenmp -o par_mergesort

sizes=(25000 50000 75000 100000 250000 500000 750000 1000000)

echo "Sequential Merge Sort"
for i in "${sizes[@]}"; do
  time=$(./seq_mergesort "$i")
  echo "size: $i -> $time" 
done

echo ""

echo "Parallel Merge Sort"
for i in "${sizes[@]}"; do
  time=$(./par_mergesort "$i")
  echo "size: $i -> $time" 
done

