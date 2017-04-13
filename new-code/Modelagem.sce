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
//Um ar que é uma constante de amplitude determinada igual a 2rad/s
//Uma matriz R 1xn, onde n>0 e corresponde ao numero de osciladores, ar corresponde a amplitude max de cada oscilador.
//Um r0 1xn, onde n>0 e corresponde ao numero de osciladores, r0 são o conjunto de condições iniciais da amplitude.
//Um m0, 1xn, onde n> 0 e corresponde ao numero de osciladores, m0 é o conjunto de condições iniciais da primeira derivada
//Um osciladores correspondente ao numero de osciladores
//Um a correspondente ao inicio do periodo do calculo do tempo.
//Um b correspondente ao fim do periodo do calculo do tempo.
//Um h correspondente ao tamanho do passo do intervalo a - b
//A função devolve uma matriz 3xn, que corresponde a amplitude de todos os osciladores em todo o espaço de tempo definido.
function r = amplitude(ar,R,r0,m0,osciladores,a,b,h)
    r = r0;
    m = m0;
    t = a:h:b;
    n = length(t)
    for i = 1:n-1
        kdm = g(ar,R,r(i,:),m(i,:),osciladores);
        km = f(m(i,:));
        m(i+1,:) = m(i,:) + kdm*h;
        r(i+1,:) = r(i,:) + km*h;
    end
endfunction