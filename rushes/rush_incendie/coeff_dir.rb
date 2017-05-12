#!/usr/bin/env ruby
# coding: utf-8
puts "Abcisse du point A ?"
xa = gets.chomp.to_f
puts "Ordonnée du point A ?"
ya = gets.chomp.to_f
puts "Abcisse du point B ?"
xb = gets.chomp.to_f
puts "Ordonnée du point B ?"
yb = gets.chomp.to_f

puts "Le coefficient directeur de cette droite est : ", (yb - ya) / (xb - xa)

exit 0
