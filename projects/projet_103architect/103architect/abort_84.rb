# coding: utf-8
# RUBY METHOD : ABORT 84
# Exit the program with a specified message and the error code 84
# Include this file in your project folder and use "require_relative 'abort_84' in your scripts
# Alexis Viguié 07/12/2015 17h51

def abort_84(str)
  $stderr.puts str
  exit 84
end
