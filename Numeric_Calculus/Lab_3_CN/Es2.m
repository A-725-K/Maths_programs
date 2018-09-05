%main script
clc;    %ripuliamo la schermata del foglio di calcolo
clear;  %Resettiamo i valori delle variabili

n = 150;  %ordine della matrice B

B = zeros(n, n);    %allocazione matrice B

%inizializzo la matrice B
for i=1:n
    for j=1:n
        if i == j
            B(i, j) = 1;
        elseif i < j
            B(i, j) = -1;
        else
            B(i, j) = 0;
        end
    end
end

fprintf('Matrice triangolare superiore B:\n');
disp(B);

val_sing = svd(B); %calcolo i valori singolari della matrice B
fprintf('Valori singolari di B:\n');
disp(val_sing);

max = val_sing(1);  %valore singolare massimo
minim = val_sing(n);  %valore singolare minimo
fprintf('Valore singolare massimo e valore singolare minimo:\n');
disp(max);
disp(minim);

cond = norm(val_sing, 2); %calcolo il condizionamento in norma 2
fprintf('Condizionamento in norma 2 di SIGMA:\n');
disp(cond);

B(n, 1) = B(n, 1) + (-2).^(2-n); %perturbo l'entrata n,1 della matrice B
fprintf('Perturbiamo l''elemento n,1 della matrice B che da 0 diventa:\n')
disp(B(n, 1));

EWB = eig(B); %calcolo gli autovalori di B perturbata
fprintf('Autovalori di B dopo la perturbazione dell''elemento n,1:\n');
disp(EWB);