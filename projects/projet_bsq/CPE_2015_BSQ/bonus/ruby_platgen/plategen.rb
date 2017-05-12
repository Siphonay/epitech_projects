#!/usr/bin/env ruby

abort "#{$PROGRAM_NAME} x y density" if ARGV.length != 3

x = ARGV[0].to_i
y = ARGV[1].to_i
density = ARGV[2].to_i

puts y

def print_and_flush(str)
  print str
  $stdout.flush
end

(1..y).each do |i|
  (1..x).each { |j| print_and_flush rand(y * 2) < density ? "o" : "." }
  print_and_flush "\n"
end

exit 0
