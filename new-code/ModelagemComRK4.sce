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
//Um "passo" correspondente ao tamanho do passo do intervalo a - b
//A função devolve uma matriz 3xn, que corresponde a amplitude de todos os osciladores em todo o espaço de tempo definido.
function r = amplitude(ar,R,r0,m0,osciladores,a,b,passo)
    r = r0;
    m = m0;
    t = a:passo:b;
    n = length(t)
    for i = 1:n-1
        kdm1 = g(ar,R,r(i,:),m(i,:),osciladores);
        km1 = f(m(i,:));
        kdm2 = g(ar,R,r(i,:)+km1.*passo/2,m(i,:)+kdm1.*passo/2,osciladores)
        km2 = f(m(i,:)+km1.*passo/2)
        kdm3 = g(ar,R,r(i,:)+km2.*passo/2,m(i,:)+kdm2.*passo/2,osciladores)
        km3 = f(m(i,:)+km2.*passo/2)   
        kdm4 = g(ar,R,r(i,:)+km3.*passo,m(i,:)+kdm3.*passo,osciladores)
        km4 = f(m(i,:)+km3.*passo)
        kdm = (kdm1 + 2.*kdm2 + 2.*kdm3 + kdm4)./6;
        km = (km1 + 2.*km2 + 2.*km3 + km4)./6;
        m(i+1,:) = m(i,:) + kdm*passo;
        r(i+1,:) = r(i,:) + km*passo;
    end
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
function x = deslocamento(ax,X,x0,exe0,osciladores,a,b,passo)
    x = x0;
    exe = exe0;
    t = a:passo:b;
    n = length(t)
    for i = 1:n-1
        kdexe1 = v(ax,X,x(i,:),exe(i,:),osciladores);
        kexe1 = p(exe(i,:));
        kdexe2 = v(ax,X,x(i,:)+kexe1.*passo/2,exe(i,:)+kdexe1.*passo/2,osciladores)
        kexe2 = p(exe(i,:)+kexe1.*passo/2)
        kdexe3 = v(ax,X,x(i,:)+kexe2.*passo/2,exe(i,:)+kdexe2.*passo/2,osciladores)
        kexe3 = p(exe(i,:)+kexe2.*passo/2)   
        kdexe4 = v(ax,X,x(i,:)+kexe3.*passo,exe(i,:)+kdexe3.*passo,osciladores)
        kexe4 = p(exe(i,:)+kexe3.*passo)
        kdexe = (kdexe1 + 2.*kdexe2 + 2.*kdexe3 + kdexe4)./6;
        kexe = (kexe1 + 2.*kexe2 + 2.*kexe3 + kexe4)./6;
        exe(i+1,:) = exe(i,:) + kdexe*passo;
        x(i+1,:) = x(i,:) + kexe*passo;
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
//Um "passo" correspondente ao tamanho do passo do intervalo a - b
// a função devolve uma matriz nx3 onde, n é o numero de osciladores
function FI = phase(w, wij,r,fi0,phi,osciladores,a,b,passo)
    FI = fi0;
    t = a:passo:b;
    n = length(t);
    for i = 1:n-1
        kdphi1 = h(w, wij,r(i,:),FI(i,:),phi,osciladores);
        kdphi2 = h(w, wij,r(i,:)+passo/2,FI(i,:)+kdphi1.*passo/2,phi,osciladores);
        kdphi3 = h(w, wij,r(i,:)+passo/2,FI(i,:)+kdphi2.*passo/2,phi,osciladores);
        kdphi4 = h(w, wij,r(i,:)+passo,FI(i,:)+kdphi3.*passo,phi,osciladores);
        kdphi = (kdphi1 + 2.*kdphi2 + 2.*kdphi3 + kdphi4)./6;       
        FI(i+1,:) = FI(i,:) + kdphi*passo;
    end
endfunction

function tetha = angulos(FI,r,n)
    for i=1:n
        tetha(:,i) = r(:,i).*sin(FI(:,i)); 
    end
endfunction
R  = [0.698132    0.20944    -0.698132];
r0 = [0 0 0];
m0 = [0 0 0];
X  = [0.698132    0.20944    0.698132];
x0 = [0 0 0];
exe0 = [0 0 0];
fi0 = [0 0 0];
ar = 2;
ax = 2;
w  = [10 10 10]
wij= gerarMatrizW(3);
phi = [0 0 0; 0 0 0; 0 0 0]; 
