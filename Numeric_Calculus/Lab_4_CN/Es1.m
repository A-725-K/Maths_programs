% main script
clc;    %Puliamo la schermata dei risultati all'avvio dello script
clear;  %Resettiamo i valori delle variabili

%Inizializziamo la matrice A
A = diag(ones(1, 9), 1) + eye(10);
fprintf('Matrice A:\n');
disp(A);

%Inizializziamo la matrice E
E = zeros(10);
E(10, 1) = 10.^(-10);

%Inizializziamo la matrice B
B = A + E;
fprintf('Matrice B:\n');
disp(B);

%Calcoliamo gli autovalori delle matrici A e B
VA = eig(A);
VB = eig(B);
fprintf('Autovalori di A:\n');
disp(VA);
fprintf('Autovalori di B:\n');
disp(VB);

%Err_ass_AB = B - A;
%disp(Err_ass_AB);

Err_rel_AB = norm(B-A)/norm(A);
fprintf('Confronto A e B in norma:\n')
disp(Err_rel_AB);

% Err_ass_VAVB = VB - VA;
% disp(Err_ass_VAVB);

Err_rel_VAVB = norm(VB - VA)/norm(VA);
fprintf('Confronto gli autovalori di A e di B in norma:\n');
disp(Err_rel_VAVB);

fprintf('--------------------------------------\n\n');

%Inizializziamo la matrice A1 con il prodotto di A e della sua trasposta (A')
A1 = (A')*A;
fprintf('Matrice A''A:\n');
disp(A1);

%Inizializziamo la matrice B1 con il prodotto di B e della sua trasposta (B')
B1 = (B')*B;
fprintf('Matrice B''B:\n');
disp(B);

%Calcoliamo gli autovalori delle matrici A1 e B1
VA1 = eig(A1);
VB1 = eig(B1);
fprintf('Autovalori di A:\n');
disp(VA1);
fprintf('Autovalori di B:\n');
disp(VB1);

%Err_ass_A1B1 = B1 - A1;
%disp(Err_ass_A1B1);

Err_rel_A1B1 = norm(B1-A1)/norm(A1);
fprintf('Confronto A''A e di B''B in norma:\n');
disp(Err_rel_A1B1);

% Err_ass_VA1VB1 = VB1 - VA1;
% disp(Err_ass_VA1VB1);

Err_rel_VA1VB1 = norm(VB1 - VA1)/norm(VA1);
fprintf('Confronto gli autovalori di A e di B in norma:\n');
disp(Err_rel_VA1VB1);