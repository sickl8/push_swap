#!/bin/sh

ARG=$(./gen $1); echo $ARG; ./push_swap $ARG | ./checker $ARG