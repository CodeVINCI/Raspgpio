#!/bin/bash

while [ 1 ]
do

      echo 1 > /sys/class/gpio/gpio4/value

      sleep 1

      echo 0 > /sys/class/gpio/gpio4/value
      sleep 1
done
