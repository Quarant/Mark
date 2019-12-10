#!/bin/bash 
g++ -o mark $(find . -name "*.cpp") $(find . -name "*.h") && ./mark 
