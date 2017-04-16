tInicio = 0;  // tempo de incio da simulação 
tFim = 25; // tempo final da simulação 
osciladores = 3; // número de osciladores 
passo = 0.01; // intervalo de tempo entre cada interação da simulação 

t = tInicio:passo:tFim 
n = length(t);


R  = [0.40944 0.29132 0.29132];
global r;
r = zeros(n,osciladores);
global m;
m  = zeros(n,osciladores);
global X;
X  = [0.0 0.0 0.0];
global x;
x = zeros(n,osciladores);
global exe; 
exe = zeros(n,osciladores);
global FI;
FI = zeros(n,osciladores);
global tetha; 
tetha = zeros(n,osciladores);
ar = 2;
ax = 2;
w  = [10 10 10]
wij= [0 0 0;0.5 0 0;0.5 0 0]
phi = [0 0 0;3.14/2 0 0;-3.14/2 0 0] // Matriz do deslocamento, exemplo se tivermos 12 osciladores teremos que ter 12 linhas e 12 colunas, 6, 6 linhas e 6 colunas.


//A seguinte função recebe uma matriz dr 1xn.
//Onde n é um número n>0 e corresponde ao número de osciladores
//A função devolve m onde m = dr.

function m = f(dr)
    m = dr
endfunction
//A seguinte função recebe uma matriz dr 1xn.
//Onde n é um número n>0 e corresponde ao número de osciladores
//A função devolve m onde exe = dx.
function exe = p(dx)
    exe = dx;
endfunction
//A seguinte função recebe: 
//Um ar que é uma constante de amplitude determinada igual a 2rad/s
//Uma matriz R 1xn, onde n>0 e corresponde ao numero de osciladores, ar corresponde a amplitude max de cada oscilador.
//Um r 1xn, onde n>0 e corresponde ao numero de osciladores, r é amplitude em determinado t.
//Um m, 1xn, onde n> 0 e corresponde ao numero de osciladores, m é a derivada primeira da amplitude.
//Um n correspondente ao numero de osciladores
//A função devolve uma matriz 1xn, que correspondem as amplitudes dos osciladores em determinado tempo.
function dm = g(ar,R,r,m,n)
    for i=1:n
        dm(1,i) = ar.*((ar/4).*(R(i)-r(i)) - m(i))
    end
endfunction
//A seguinte função recebe: 
//Um ax que é uma constante de amplitude determinada igual a 2rad/s
//Uma matriz X 1xn, onde n>0 e corresponde ao numero de osciladores, ax corresponde ao deslocamento max
//Um x 1xn, onde n>0 e corresponde ao numero de osciladores, x é o deslocamento em determinado t.
//Um exe, 1xn, onde n> 0 e corresponde ao numero de osciladores, exe é a derivada primeira do deslocamento.
//Um n correspondente ao numero de osciladores
//A função devolve uma matriz 1xn, que correspondem aos deslocamentos dos osciladores em determinado tempo.
function dexe = v(ax,X,x,exe,n)
    for i=1:n
        dexe(1,i) = ax.*((ax/4).*(X(i)-x(i)) - exe(i))
    end
endfunction
//A seguinte função recebe:
// Um n, n > 0, onde n corresponde ao numero de osciladores.
// A função devolve uma matriz nxn 
function w=gerarMatrizW(n)
    for i=1:n
        for j=1:n
            if (i==j) then
                w(i,j) = 0; 
            else
                w(i,j) = 0.5; 
            end
        end
    end
endfunction

//A seguinte função recebe:
// w uma matriz 1xn, onde n é o numero de osciladores.
// wij uma matriz nxn, onde n>0, n corresponde ao numero de osciladores.
// r, uma matriz 1xn, onde n corresponde ao numero de osciladores.
// fi, uma matriz 1xn onde n corresponde ao numero de osciladores.
// phi uma matriz nxn onde n corresponde ao numero de osciladores.
// n, n>0 n corresponde ao numero de osciladores
// A função devolve uma matriz 1xn onde n corresponde ao numero de osciladores.
function dphi = h(w, wij,r,fi,phi,n)
    for i=1:n
        dphi(1,i) = w(i);
        for j=1:n
            dphi(1,i) = dphi(1,i) + wij(i,j)*r(1,j)*sin(fi(1,j)- fi(1,i) - phi(i,j));
        end
    end
endfunction
//A seguinte função recebe: 
//Um ar que é uma constante de amplitude determinada igual a 2rad/s
//Uma matriz R 1xn, onde n>0 e corresponde ao numero de osciladores, ar corresponde a amplitude max de cada oscilador.
//Um r0 1xn, onde n>0 e corresponde ao numero de osciladores, r0 são o conjunto de condições iniciais da amplitude.
//Um m0, 1xn, onde n> 0 e corresponde ao numero de osciladores, m0 é o conjunto de condições iniciais da primeira derivada
//Um osciladores correspondente ao numero de osciladores
//Um a correspondente ao inicio do periodo do calculo do tempo.
//Um b correspondente ao fim do periodo do calculo do tempo.
//Um  correspondente ao tamanho do passo do intervalo a - b
//A função devolve uma matriz 3xn, que corresponde a amplitude de todos os osciladores em todo o espaço de tempo definido.
function [x,exe] = deslocamento(ax,X,x,exe,osciladores,i)
    kdexe = v(ax,X,x(i,:),exe(i,:),osciladores);
    kexe = p(exe(i,:));
    exe(i+1,:) = exe(i,:) + kdexe*passo;
    x(i+1,:) = x(i,:) + kexe*passo;
    //end
endfunction
//A seguinte função recebe: 
//Um ax que é uma constante de deslocamento determinada igual a 2rad/s
//Uma matriz X 1xn, onde n>0 e corresponde ao numero de osciladores, ax corresponde ao deslocamento max.
//Um x0 1xn, onde n>0 e corresponde ao numero de osciladores, rx são o conjunto de condições iniciais do deslocamento.
//Um exe0, 1xn, onde n> 0 e corresponde ao numero de osciladores, exe0 é o conjunto de condições iniciais da primeira derivada
//Um "osciladores" correspondente ao numero de osciladores
//Um a correspondente ao inicio do periodo do calculo do tempo.
//Um b correspondente ao fim do periodo do calculo do tempo.
//Um "passo" correspondente ao tamanho do passo do intervalo a - b
//A função devolve uma matriz 3xn, que corresponde ao deslocamento de todos os osciladores em todo o espaço de tempo definido.
function [r,m] = amplitude(ar,R,r,m,osciladores,i)
    kdm = g(ar,R,r(i,:),m(i,:),osciladores);
    km = f(m(i,:));
    m(i+1,:) = m(i,:) + kdm*passo;
    r(i+1,:) = r(i,:) + km*passo;
endfunction

//A seguinte função recebe:
// w uma matriz 1xn, onde n é o numero de osciladores.
// wij uma matriz nxn, onde n>0, n corresponde ao numero de osciladores.
// r, uma matriz 1xn, onde n corresponde ao numero de osciladores.
// fi, uma matriz 1xn onde n corresponde ao numero de osciladores.
// phi uma matriz nxn onde n corresponde ao numero de osciladores.
// osciladores, osciladores>0 n corresponde ao numero de osciladores
// A função devolve uma matriz 1xn onde n corresponde ao numero de osciladores.
//Um a correspondente ao inicio do periodo do calculo do tempo.
//Um b correspondente ao fim do periodo do calculo do tempo.
//Um passo correspondente ao tamanho do passo do intervalo a - b
// a função devolve uma matriz nx3 onde, n é o numero de osciladores
function FI = phase(w, wij,r,FI,phi,osciladores,i)
         // h 
        dphi = zeros(1,osciladores)
        for oi=1:osciladores
            dphi(1,oi) = w(oi);
            for j=1:osciladores
                dphi(1,oi) = dphi(1,oi) + wij(oi,j)*r(i,j)*sin(FI(i,j)- FI(i,oi) - phi(oi,j));
                //disp(r(i,j));
            end
        end
        
        kdphi =  dphi; //h(w, wij,r(i,:),FI(i,:),phi,osciladores);
        FI(i+1,:) = FI(i,:) + kdphi*passo;
    //end
endfunction
//A seguinte função recebe:
//FI uma matriz nx3, onde n é o numero de linhas calculada a partir de um metodo númerico.
//r  uma matriz nx3, onde n é o numero de linhas calculada a partir de um metodo númerico.
//x  uma matriz nx3, onde n é o numero de linhas calculada a partir de um metodo númerico.
//n numero de osciladores.
// a função devolve os angulos de todos os osciladores 
function tetha = angulos(tetha, FI,r,x,n)
    for i=1:n
        tetha(:,i) = x(:,i)+r(:,i).*sin(FI(:,i)); 
    end
endfunction



// calcula os valores das variáveis do sistema para cada iteração i 
for i = 1:n-1 
    [x,exe] = deslocamento(ax,X,x,exe,osciladores,i);
    [r,m] = amplitude(ar,R,r,m,osciladores,i);
    FI = phase(w, wij,r,FI,phi,osciladores,i);
     
end
tetha = angulos(tetha, FI,r,x,osciladores);

tp = tInicio:passo:tFim 
plot(tp,tetha);
//plot(tp,r); 
//plot(tp,x)
