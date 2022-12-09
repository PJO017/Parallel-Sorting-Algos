#!/bin/bash
echo "Compiling..."

g++ seq_mergesort.cpp -o seq_mergesort.o
g++ par_mergesort.cpp -fopenmp -o par_mergesort.o

sizes=(25000 50000 75000 100000 250000 500000 750000 1000000)

echo "---Sequential Merge Sort---"
echo ""
echo "Random Input:"
for i in "${sizes[@]}"; do
  time=$(./seq_mergesort.o "$i" "../data/Random/randomArray_$i")
  echo "size: $i -> $time" 
done

echo ""
echo "Sorted Input:"
for i in "${sizes[@]}"; do
  time=$(./seq_mergesort.o "$i" "../data/Sorted/sorted_$i")
  echo "size: $i -> $time" 
done

echo ""
echo "Reverse Sorted Input:"
for i in "${sizes[@]}"; do
  time=$(./seq_mergesort.o "$i" "../data/ReverseSorted/reverseSortedArray_$i")
  echo "size: $i -> $time" 
done


echo ""

echo "---Parallel Merge Sort---"
echo ""
echo "Random Input:"

for i in "${sizes[@]}"; do
  time=$(./par_mergesort.o "$i" "../data/Random/randomArray_$i")
  echo "size: $i -> $time" 
done

echo ""
echo "Sorted Input:"
for i in "${sizes[@]}"; do
  time=$(./par_mergesort.o "$i" "../data/Sorted/sorted_$i")
  echo "size: $i -> $time" 
done

echo ""
echo "Reverse Sorted Input:"
for i in "${sizes[@]}"; do
  time=$(./par_mergesort.o "$i" "../data/ReverseSorted/reverseSortedArray_$i")
  echo "size: $i -> $time" 
done

rm seq_mergesort.o par_mergesort.o
echo ""
echo "done."
