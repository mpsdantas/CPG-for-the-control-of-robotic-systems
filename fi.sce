//Definição da função descrita no artigo.
// dFi é a derivada de fi em relação ao tempo.
// omega é a matriz omega definida no artigo.
// cOnda é o comprimento de onda definido por omega.
//r é a matriz de amplitude dos osciladores.
//vetorFi é o vetor de angulos.
// n é o número de osciladores.
function [dFI,omega] = f(cOnda,r,vetorFI,n)
    dFI = zeros(length(vetorFI(:,1)),n)
    for i = 1:n
        for j = 1:n
            if i=j then 
                omega(i,j) = 0;
            else
                omega(i,j) = 0.5;
            end
        end 
    end
    
    for i = 1:n
        dFI(:,i) = cOnda(i);
        for j = 1:n
            dFI(:,j) = dFI(i,j) + omega(i,j)*r(:,j)*sin(vetorFI(j) - vetorFI(i))
        end
    end
endfunction
// aplicação do método de euler
function [fi,tempo] = phase(a,b,h,cOnda,r,n)
    tempo = a:h:b // vetor tempo de 0 a 15 com h = 0.05
    m = length(tempo); // pegando tamanho do vetor tempo
    fi = zeros(m,n) ; // criando uma matriz fi.
    for i=1:n // percorrendo as colunas
        for j = 1:m-1 //percorrendo as linhas
            k = f(cOnda,r,fi(:,i),n) // definindo a função do passo anterior  
            fi(j+1,i) = fi(j,i) + k(j,i)*h // metodo de euler
        end
    end 
endfunction
cOnda = [10 10 10]
[fi,tempo] = phase(0,5,0.05,cOnda,r,3)