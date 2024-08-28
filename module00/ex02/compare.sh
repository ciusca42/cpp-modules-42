# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compare.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 20:09:03 by ciusca            #+#    #+#              #
#    Updated: 2024/08/28 20:09:27 by ciusca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if [ $# != 2 ]; then
	echo "usage: file1 | file2";
	exit 1
fi

line=0

while IFS= read -r line1 && IFS= read -r line2 <&3; do
	#echo "test1 $line1"
	#echo "test2 $line2"
	line1=$(echo "$line1" | cut -c 19-)   
    line2=$(echo "$line2" | cut -c 19-)
	i=$((i+1))
	test "$line1" = "$line2"
	if [ $? -eq 1 ]; then
		echo "\n\tdifference at line: \033[0;32m $i \033[0m\n"
		echo "\tfile1: \033[0;31m $line1 \033[0m"
		echo "\tfile2: \033[0;31m $line2 \033[0m\n"
		exit 1
	fi	
done < "$1" 3< "$2"

echo "\033[0;32m\n\tThe files are the same! \033[0m\n"

exit 0
