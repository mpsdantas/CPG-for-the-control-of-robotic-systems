//A seguinte função recebe uma matriz dr 1xn.
//Onde n é um número n>0 e corresponde ao número de osciladores
//A função devolve m onde m = dr.

function m = f(dr)
    m = dr
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
function r = amplitude(ar,R,r0,m0,osciladores,a,b,passo)
    r = r0;
    m = m0;
    t = a:passo:b;
    n = length(t)
    for i = 1:n-1
        kdm = g(ar,R,r(i,:),m(i,:),osciladores);
        km = f(m(i,:));
        m(i+1,:) = m(i,:) + kdm*passo;
        r(i+1,:) = r(i,:) + km*passo;
    end
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
function FI = phase(w, wij,r,fi0,phi,osciladores,a,b,passo)
    FI = fi0;
    t = a:passo:b;
    n = length(t);
    for i = 1:n-1
        kdphi = h(w, wij,r(i,:),FI(i,:),phi,osciladores);
        FI(i+1,:) = FI(i,:) + kdphi*passo;
    end
endfunction

R  = [0.698132    0.20944    -0.698132];
r0 = [0 0 0];
m0 = [0 0 0];
fi0 = [0 0 0];
ar = 2;
w  = [10 10 10]
wij= gerarMatrizW(3);
phi = [0 0 0; 0 0 0; 0 0 0]; 


