# Quick Start
[![Build Status](https://travis-ci.org/iyak/smith_waterman.svg?branch=master)](https://travis-ci.org/iyak/smith_waterman)
## Introduction
This program is an implementation of smith-waterman algorithm.

## Installation
```
$ git clone https://github.com/iyak/smith_waterman
$ cd smith_waterman
$ ./waf distclean configure build install
```

## Usage
```
$ sw ACCGTT ACGTCA
ACCGT-T
A-CGTCA
```
`-m, --match` set the match score and `-M, --mismatch` set the mismatch / gap penalty.
