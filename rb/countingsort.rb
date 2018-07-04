#!/usr/bin/env ruby
#
def sort(input)
	output = []
	counts = Array.new(input.max + 1, 0)
	input.each do |i|
		counts[i] += 1
	end
	for i in 0..(counts.size - 1)
		counts[i].times do
			output << i
		end
	end
	return output
end

inp = []
while i = STDIN.gets
	inp << i.to_i
end
p sort inp
