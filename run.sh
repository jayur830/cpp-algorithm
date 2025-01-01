# if [ -z "$1" ]; then
#     echo "Usage: ./run.sh <source_file>"
#     exit 1
# fi
g++ -std=c++14 -Wall *.cpp -o ./app.out && ./app.out && rm ./app.out