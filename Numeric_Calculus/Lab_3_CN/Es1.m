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

fprintf('Matrice A:\n');
disp(A);

%Trasposta di A
At = A';

%Calcoliamo le 3 matrici SVD
[UA, SA, VA] = svd(A);
[UAt, SAt, VAt] = svd(At);

%Calcoliamo gli autovalori di A*At e At*A
EV_AAt = eig(A*At);
EV_AtA = eig(At*A);

fprintf('Valori singolari di A:\n');
disp(SA);
fprintf('Autovalori di AAt:\n');
disp(EV_AAt);
fprintf('Autovalori di AtA:\n');
disp(EV_AtA);

%Calcoliamo immagine e nucleo di A
Im_A = orth(A);
Ker_A = null(A);

%Calcoliamo immagine e nucleo di At
Im_At = orth(At);
Ker_At = null(At);

fprintf('Immagine di A:\n');
disp(Im_A);
fprintf('Matrice dei valori singolari sinistri (UA):\n');
disp(UA);

fprintf('Immagine di At:\n');
disp(Im_At);
fprintf('Matrice dei valori singolari sinistri (UAt):\n');
disp(UAt);

fprintf('Nucleo di A:\n');
disp(Ker_A);    %vuoto
fprintf('Il nucleo di A e'' vuoto (contiene solo la soluzione banale {0}).\n\n');

fprintf('Matrice dei valori singolari destri (VA):\n');
disp(VA);

fprintf('Nucleo di At:\n');
disp(Ker_At);
fprintf('Matrice dei valori singolari destri (VAt):\n');
disp(VAt);