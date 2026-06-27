# Read from the file file.txt and output all valid phone numbers to stdout

mapfile -t lines_array < "file.txt"

regex="^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$"

# Iterate through each line
for line in "${lines_array[@]}"; do
    if [[ $line =~ $regex ]]; then
        echo "$line"
    fi
done
