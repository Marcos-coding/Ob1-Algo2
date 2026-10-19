num="$1"

for input in $(printf '%s\n' ejercicio$num/*.in.txt | sort -t/ -k2 -n); do
    expected="${input%.in.txt}.out.txt"
    ./"..\ej$num.exe" < "$input" > /tmp/salida.txt
    if diff --strip-trailing-cr /tmp/salida.txt "$expected" > /dev/null 2>&1; then
        echo "OK: $input"
    else
        echo "FALLO: $input"
    fi
done