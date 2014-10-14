let s:punct = '\v[!#$%&()*+,\-./:;<=>?@[\\\]^_`{|}~]'

function s:SyMatch(name, re, term)
    let l:exp = "syntax match ".a:name." '\v".a:re."' ".a:term
    exec l:exp
endfunction

call s:SyMatch("rpnErr", '\S', "")
call s:SyMatch("rpnWord", '[a-zA-Z]+', "")
call s:SyMatch("rpnSymbol", s:punct.'+', "")
call s:SyMatch("rpnBraces", s:punct.'@<![{}]'.s:punct.'@!', "")
call s:SyMatch("rpnDigit", '[-+]?\d+(\.\d+)?', "")
sy region rpnString start='\v[rb]*"' end='\v"' contains=rpnStringEscape
sy region rpnString start='\v[rb]*'' end='\v'' contains=rpnStringEscape,rpnBadEsc
call s:SyMatch("rpnBadEsc", '\', "contained")
call s:SyMatch("rpnStringEscape", '\[abfvrnte0]', "contained")

hi link rpnDigit Number
hi link rpnWord Identifier
hi link rpnSymbol Operator
hi link rpnErr Error
hi link rpnBadEsc Error
hi link rpnStringEscape Special
hi link rpnString String
hi link rpnBraces Delimiter
