#!/usr/bin/ruby -w

require 'fileutils'

FileUtils.rm_rf "./src/*"

FileUtils.cp_r '../cmake_utils/.', "./cmake_utils";

FileUtils.cp_r '../src/.', "./src";
