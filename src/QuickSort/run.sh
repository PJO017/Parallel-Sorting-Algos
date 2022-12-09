#!/bin/bash
echo "Compiling..."

g++ SeqQuicksort.cpp -o SeqQuicksort.o
g++ ParQuicksort.cpp -fopenmp -o ParQuicksort.o

sizes=(25000 50000 75000 100000 250000 500000 750000 1000000)
threads=(1 2 4 6)

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
  time=$(./SeqQuicksort.o "$i" "../data/Sorted/sorted_$i")
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
for j in "${threads[@]}"; do
  for i in "${sizes[@]}"; do
    time=$(./ParQuicksort.o "$i" "../data/Random/randomArray_$i" "$j")
    echo "threads: $j; size: $i -> $time" 
  done
done

echo ""
echo "Sorted Input:"
for j in "${threads[@]}"; do
  for i in "${sizes[@]}"; do
    time=$(./ParQuicksort.o "$i" "../data/Sorted/sorted_$i" "$j")
    echo "threads: $j; size: $i -> $time" 
  done
done

echo ""
echo "Reverse Sorted Input:"
for j in "${threads[@]}"; do
  for i in "${sizes[@]}"; do
    time=$(./ParQuicksort.o "$i" "../data/ReverseSorted/reverseSortedArray_$i" "$j")
    echo "size: $i -> $time" 
  done
done

rm SeqQuicksort.o ParQuicksort.o
echo ""
echo "done."
