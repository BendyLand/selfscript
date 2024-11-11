cp "ex1.txt" "ex2.txt"
cp "ex2.txt" "ex3.txt"
mv "ex3.txt" "ex4.txt"
rm "ex4.txt"
mkdir "ex_dir"

has_user = check_env $USER
puts has_user # true/false

name = "Steve"
set_env $TEST = "This is a test"
puts name
puts $TEST
unset_env $TEST

exec ls

puts "This is a message"

name = prompt "What is your name?"
puts name

is_name = confirm "Is this your name?"
if is_name then
	puts "This is my name!"
else
	puts "This is not my name."
end

for i in 0..10 do
	puts i
end

label Location

x = 8
puts "You should see this twice"
x += 1

if x < 10 then
	goto Location
end

download "example.com/txtfile.txt" "example_file.txt"
upload "example_file.txt" "example_dest.com/upload"

