# coding: utf-8
# RUBY METHOD : PRINT AND FLUSH
# Print in standard output then flush it to keep it synchronized
# Include this file in your project folder and use "require_relative "print_and_flush" in your scripts
# Alexis Viguié 02/12/2015 11h12

def print_and_flush(str)
  print str
  $stdout.flush
end
