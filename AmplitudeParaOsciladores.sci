    //Modelagem da EDO
    // EDO Original ------>>> r''(i)= ar*(ar/4*(R(i)-r(i)) - r'(i))
    // z = dr/dt ----- dz/dt = d²r/dt²
    // Sistema de EDOS:
    // dr/dt = z
    // dz/dt = ar*(ar/4*(R(i)-r(i)) - z)
function derivadaSegunda = g(r,tempo,z)
    derivadaSegunda = z
endfunction
function derivadaPrimeira = f(r,tempo,z,R,ar)
    derivadaPrimeira = ar*(ar/4 *(R-r) -z)
endfunction
function [tempo,amplitude,derivada] = metodoEuler(a,b,h,amplitudeMax,ampliduteAlvo,condicaoInicialDeerivadaPrimeira,condicaoIncialDerivadaSegunda)
    // Aplicação do metodo de Euler
    //y(s+1) = y(s) + h*(f(x(s),y(s),z(s)))
    // a é o ponto inicial b é o ponto final e h é o passo, r0 condição r inicial e z0 condição z inicial.
    tempo = a:h:b;
    n = length(t);
    amplitude(1) = condicaoInicialDeerivadaPrimeira;
    derivada(1)  = condicaoIncialDerivadaSegunda;
    for passo=1:n-1
        Kderivada  = f(amplitude(passo),tempo(passo),derivada(passo),amplitudeMax,ampliduteAlvo);
        Kamplitude = g(amplitude(passo),tempo(passo),derivada(passo)); 
        derivada(passo+1)  = z(passo) + Kderivada*h;
        amplitude(passo+1) = r(passo) + Kamplitude*h;
    end
endfunction
function [r,tempo] = osciladores(a,b,h,amplitudeMax,ampliduteAlvo,condicaoInicialDeerivadaPrimeira,condicaoIncialDerivadaSegunda,n)
    for i = 1:n
        [tempo,amplitude,derivada] = metodoEuler(a,b,h,amplitudeMax(i),ampliduteAlvo(i),condicaoInicialDeerivadaPrimeira,condicaoIncialDerivadaSegunda)
        r(:,i) = amplitude;
    end
endfunction
//[tempo,amplitude,derivada] = metodoEuler(0,5,0.05,0,0)
//plot(tempo,amplitude)
//plot(tempo,derivada,'r')

