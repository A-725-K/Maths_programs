% main script
clc;    %Puliamo la schermata dei risultati all'avvio dello script
clear;  %Resettiamo i valori delle variabili

%Inizializziamo la matrice di incidenza Ag
Ag = [0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0;
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
      1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0;
      1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0;
      1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0;
      1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0;
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
      0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0;
      0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0;
      0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1;
      0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 ];

fprintf('Matrice di adiacenza del grafo:\n');
disp(Ag);

%Calcoliamo gli autovalori di Ag
DAg = eig(Ag);
fprintf('Autovalori di Ag:\n')
disp(DAg);

%Calcolo le dimensioni di Ag
[row, col] = size(Ag); 

%Calcolo autovettori di Ag
[VAg, DAg] = eig(Ag);

%Autovalore massimo di Ag
max_ew = abs(DAg(1,1));
for i=2:row
    if max_ew <= abs(DAg(i,i))
        max_ew = abs(DAg(i,i));
    end
end
fprintf('Autovalore massimo in modulo:\n');
disp(max_ew);

fprintf('Autovettori di Ag:\n');
disp(VAg);

D = zeros(11);  %allochiamo la matrice D per migliorare i calcoli

%Inizializzazione matrice D

for i=1:row
    diagElem = 0;
    for j=1:col
        if Ag(i, j) == 1
            diagElem = diagElem + 1;
        end
    end
    D(i, i) = diagElem;
end

fprintf('La matrice D sulla diagonale ha il numero di archi connessi al nodo i-esimo:\n');
disp(D);

%Inizializzo la matrice di Google G con il prodotto Ag * D^(-1)
G = Ag * inv(D);
fprintf('Matrice di Google G (Ag * D^(-1)):\n');
disp(G);

%Calcolo gli autovalori di G
EWG = eig(G);
fprintf('Autovalori di G:\n');
disp(EWG);

%Autovalore massimo di G
max_ew = abs(max(EWG));
fprintf('Autovalore massimo in modulo:\n');
disp(max_ew);

%Calcolo gli autovettori di G
[EVG, EWG] = eig(G);
fprintf('Autovettori di G:\n');
disp(EVG);