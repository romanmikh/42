#!/bin/bash
find . -name "*.sh" -printf '%f\n' | rev | cut -c4- | rev
