%main script
clc;    %Puliamo la schermata dei risultati all'avvio dello script
clear;  %Resettiamo i valori delle variabili

%Inizializzo la matrice A
A = [1, -1, 2;
     -2, 0, 5;
     6, -3, 6 ];

fprintf('Matrice A:\n');
disp(A);

fprintf('AUTOVALORI DI A IN MODULO:\n');
EW = sort(abs(eig(A)), 'descend');
disp(EW);

V1 = ones(3,1);    %primo vettore di prova
V2 = [3; 10; 4];   %secondo vettore di prova
fprintf('Vettori di prova:\nV1:\n');
disp(V1);
fprintf('V2:\n');
disp(V2);

fprintf('---------- METODO DELLE POTENZE ----------\n\n');

l1 = 1;     %autovettore approssimato al ciclo attuale
l1_old = 0; %autovettore approssimato al ciclo precedente

%metodo delle potenze iterativo
for i=1:100
    if abs(l1_old - l1) < eps*(i-1)     %condizione di uscita dal ciclo
       break;
    end
    w1 = A*V1;               %calcolo dei termini della successione
    l1_old = l1;             %salvo gli autovalori precedenti
    l1 = (V1'*w1)/(V1'*V1);  %approssimazione degli autovalori
    V1 = w1/norm(w1,2);      %normalizziamo i vettori
end

l2 = 0;            %autovalore approssimato al ciclo attuale
l2_old = 0;        %autovalore approssimato al ciclo precedente

%metodo delle potenze iterativo
for j=1:100        
    if abs(l2_old - l2) < eps*(j-1) %condizione di uscita dal ciclo
       break;
    end
    w2 = A*V2;              %calcolo dei termini della successione
    l2_old = l2;            %salvo gli autovalori precedenti
    l2 = (V2'*w2)/(V2'*V2); %approssimazione degli autovalori
    V2 = w2/norm(w2,2);     %normalizziamo i vettori
end

fprintf('AUTOVALORI FINALI:\n');
disp(l1);
disp(l2);

fprintf('AUTOVETTORI FINALI:\n');
disp(V1);
disp(V2);

%Calcoliamo la velocita' di convergenza del metodo delle potenze
v_pot1 = (EW(2)/EW(1)).^i;
v_pot2 = (EW(2)/EW(1)).^j;

fprintf('VELOCITA'' DI CONVERGENZA:\n');
disp(v_pot1);
disp(v_pot2);

fprintf('NUMERO DI ITERAZIONI:\n');
disp(i);
disp(j);

fprintf('---------- METODO POTENZE INVERSE ----------\n\n');

p = 4.6;    %scegliamo lo shift
y1 = ones(3,1);    %primo vettore di prova
y2 = [3; 10; 4];   %secondo vettore di prova

fprintf('SHIFT ----->\t%.4f\n\n', p);

rt1 = 0;
rt1_old = 0;
%metodo delle potenze inverse
for i=1:100
    if abs(rt1_old - rt1) < eps*(i-1)   %condizione di uscita dal ciclo
       break;
    end
    w1 = (A - p*eye(3,3))\y1;   %calcoliamo il termine i-esimo della serie
    r1 = (y1'*w1)/(y1'*y1);     %aggiorniamo lo shift
    y1 = w1/norm(w1,2);         %normalizziamo il vettore
    rt1_old = rt1;
    rt1 = p + 1/r1;             %approssimiamo gli autovalori
end

rt2 = 0;
rt2_old = 0;
%metodo delle potenze inverse
for j=1:100
    if abs(rt2_old -rt2) < eps*(j-1)    %condizione di uscita dal ciclo
       break;
    end
    w2 = (A - p*eye(3,3))\y2;   %calcoliamo il termine i-esimo della serie
    r2 = (y2'*w2)/(y2'*y2);     %aggiorniamo lo shift
    y2 = w2/norm(w2,2);         %normalizziamo il vettore
    rt2_old = rt2;
    rt2 = p + 1/r2;             %approssimiamo gli autovalori
end

fprintf('AUTOVALORI FINALI:\n');
disp(rt1);
disp(rt2);

fprintf('AUTOVETTORI FINALI:\n');
disp(y1);
disp(y2);

temp = sort(abs(eig(A)-p*ones(3,1)));   %vettore contenente la differenza in modulo tra i lambda e p

%Calcoliamo la velocita' di convergenza del metodo delle potenze inverse
v_potinv1 = (temp(1)/temp(2)).^i;
v_potinv2 = (temp(1)/temp(2)).^j;
fprintf('VELOCITA'' DI CONVERGENZA:\n');
disp(v_potinv1);
disp(v_potinv2);

fprintf('NUMERO DI ITERAZIONI:\n');
disp(i);
disp(j);