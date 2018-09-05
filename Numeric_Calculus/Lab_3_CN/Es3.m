%main script
clc;    %ripuliamo la schermata del foglio di calcolo
clear;  %Resettiamo i valori delle variabili

m = 10; %costante
A = zeros(m,3); %Allochiamo la matrice in memoria per fare i calcoli piu' velocemente

%Inizilizzazione della matrice A
for i=1:m
    for j=1:3
        A(i, j) = (i/m).^(j-1);
    end
end

fprintf('Matrice dei coefficienti:\n');
disp(A);

y = sin(A(1:m, 2)); %inizializzo la matrice y
fprintf('Termine noto:\n');
disp(y);

%********************************************%
%soluzioni ai minimi quarati del sistema Ac=y
%********************************************%

%METODO SVD
fprintf('---------- SVD ----------\n\n');
[U,S,V] = svd(A);   %ottengo la decomposizione ai valori singolari di A
U = U';     %considero l'inversa della matrice singolare sinistra
c_svd = zeros(3,1);  %inizializzo il vettore delle soluzioni fare i calcoli piu' velocemente

for i=1:3
    c_svd = c_svd + U(i,1:m)*y(1:m)*V(1:3,i)/S(i,i);   %calcolo la pseudoinversa
end
disp(c_svd);

%FATTORIZZAZIONE QR
fprintf('---------- FATTORIZZAZIONE QR ----------\n\n');
[Q, R] = qr(A); %calcolo le matrici Q ed R tali che A=Q(R|0)
H = Q'*y;   %il vettore H e' dato dal prodotto Qt * y
c_qr = R\H; %risolvo il sistema R*c_qr=H, dove c_qr e' la soluzione
disp(c_qr);

%METODO DELLE EQUAZIONI NORMALI
fprintf('---------- EQUAZIONI NORMALI ----------\n\n');
coeff = A'*A;   %calcolo la matrice dei coefficienti
term_noto = A'*y;   %calcolo il termine noto
c_eqnorm = coeff\term_noto; %risolvo il sistema delle equazioni normali
disp(c_eqnorm);

%METODO DI MATLAB
fprintf('---------- A\\y (comando di Matlab) ----------\n\n');
c_mat = A\y;    %calcolo la soluzione con il comando di matlab \
disp(c_mat);