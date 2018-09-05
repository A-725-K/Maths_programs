% main script
clear;  %azzeriamo le variabili in memoria
clc;    %ripuliamo la schermata

m = 58; %costante

%inizializzazione matrice A
A = [3,1,-1,0;
     0,7,-3,0;
     0,-3,9,-2;
     0,0,4,-10;];

%inizializzazione matrice B
B = [2,4,-2,0;
     1,3,0,1;
     3,-1,1,2;
     0,-1,2,1;];

%inizializzazione matrice di Pascal
P = pascal(10);

%inizializzazione matrice tridiagonale
T = zeros(m,m);
for i=1:m
    for j=1:m
        if i == j
            T(i,j) = 2;
        elseif abs(i-j) == 1
            T(i,j) = -1;
        else
            T(i,j) = 0;
        end
    end
end

%studio dei condizionamenti delle matrici
fprintf('Condizionamento A:\n');
disp(cond(A));
fprintf('Condizionamento B:\n');
disp(cond(B));
fprintf('Condizionamento P:\n');
disp(cond(P));
fprintf('Condizionamento T:\n');
disp(cond(T));
