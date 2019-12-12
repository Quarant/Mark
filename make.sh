#!/bin/bash 
g++ -o mark $(find /home/quarant/cb/Mark -name "*.cpp") $(find /home/quarant/cb/Mark -name "*.h") && /home/quarant/cb/Mark/mark ; find /home/quarant/cb/Mark -name "*.so" -delete
