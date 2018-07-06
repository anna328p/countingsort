#!/usr/bin/env ruby

def sort(input)
  output = []
  counts = Array.new(input.max + 1, 0)
  input.each do |i|
    counts[i] += 1
  end
  counts.each_with_index do |val, index|
    val.times { output << index }
  end
  output
end

puts sort(ARGV.map(&:to_i)).join ' '
