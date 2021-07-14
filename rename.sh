#!/bin/bash

for i in leetcode/* ; do
  for filename in "$i/"* ; do
    echo $filename
  done
done
