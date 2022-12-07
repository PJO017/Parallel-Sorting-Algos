#!/bin/bash
echo "Compiling..."

g++ SeqQuicksort.cpp -o SeqQuicksort.o
g++ ParQuicksort.cpp -fopenmp -o ParQuicksort.o

sizes=(25000 50000 75000 100000 250000 500000 750000 1000000)

echo "---Sequential QuickSort Sort---"
echo ""
echo "Random Input:"
for i in "${sizes[@]}"; do
  time=$(./SeqQuicksort.o "$i" "../data/Random/randomArray_$i")
  echo "size: $i -> $time" 
done

echo ""
echo "Sorted Input:"
for i in "${sizes[@]}"; do
  time=$(./SeqQuicksort.o.o "$i" "../data/Sorted/sorted_$i")
  echo "size: $i -> $time" 
done

echo ""
echo "Reverse Sorted Input:"
for i in "${sizes[@]}"; do
  time=$(./SeqQuicksort.o "$i" "../data/ReverseSorted/reverseSortedArray_$i")
  echo "size: $i -> $time" 
done

echo ""

echo "---Parallel QuickSort---"
echo ""
echo "Random Input:"
for i in "${sizes[@]}"; do
  time=$(./ParQuicksort.o "$i" "../data/Random/randomArray_$i")
  echo "size: $i -> $time" 
done

echo ""
echo "Sorted Input:"
for i in "${sizes[@]}"; do
  time=$(./ParQuicksort.o "$i" "../data/Sorted/sorted_$i")
  echo "size: $i -> $time" 
done

echo ""
echo "Reverse Sorted Input:"
for i in "${sizes[@]}"; do
  time=$(./ParQuicksort.o "$i" "../data/ReverseSorted/reverseSortedArray_$i")
  echo "size: $i -> $time" 
done

rm SeqQuicksort.o ParQuicksort.o
echo ""
echo "done."
