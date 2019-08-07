#! /usr/bin/env sh
lib/cpplint/cpplint.py --filter=-build/header_guard --recursive include/*
lib/cpplint/cpplint.py --filter=-build/header_guard --recursive src/*
