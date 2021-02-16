# HACKERRANK FRACTALS LINUX SHELL - INPUT  1 <= N <= 5

ROWS=63
COLS=100

declare -a fractal

function print_fractal() {  
  for ((i=0; i<ROWS; i++)); do
    for ((j=0; j<COLS; j++)); do
      echo -n "${fractal[$((i*COLS + j))]}"
    done
    echo ''
  done
}

function draw_fractal() {
  local N=$1
  local start_i=$2
  local start_j=$3
  local pattern=$4
  
  # [DEBUG PRINT]
  #echo "N=$N start_i=$start_i start_j=$start_j pattern=$pattern"
  
  if [[ $N -eq 0 ]]; then
    return
  fi
  
  # draw vertical line
  for ((i=0; i<$pattern; i++)) do
    fractal[$((start_i*COLS + start_j))]="1"
    ((--start_i))
  done
  
  # draw the V
  local left=$((start_j-1))
  local right=$((start_j+1))
  for ((i=0; i<$pattern; i++)); do
    fractal[$((start_i*COLS + left))]="1"
    fractal[$((start_i*COLS + right))]="1"
    ((--left))
    ((++right))
    ((--start_i))
  done
  
  # recursively draw other Y
  draw_fractal $((N-1)) $start_i $((left+1)) $((pattern / 2))
  draw_fractal $((N-1)) $start_i $((right-1)) $((pattern / 2))
}

function build_fractal() {
  for ((i=0; i<ROWS; i++)); do
    for ((j=0; j<COLS; j++)); do
      fractal+=("_")
    done
  done  
}

read -r N
build_fractal
draw_fractal $N $((ROWS - 1)) $((COLS/2 - 1)) 16
print_fractal
