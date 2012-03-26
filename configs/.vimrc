"author: dong
"mail: systemapi@hanmail.net
"-----------------------------------------------------------------
" HELP
" rename-files
"-----------------------------------------------------------------
" TIP
"--------------------- 
" intro.txt : 도움말에서 각 기호 설명 
"--------------------- 
" :e ftp://10.1.8.1/~/filename
"--------------------- 
" :args *.c
" :argdo set ff=unix | update
"--------------------- 
" :new $VIM/syntax/colortest.vim | so %
" :so $VIM/syntax/hitest.vim
"--------------------- 
" :options
"--------------------- 
" 파일 몸체를 fold
" :set fdm=indent
" 원래
" :set fdm=manual
"--------------------- 
" printoptions: 수첩에 붙이기 좋게
" 아래 설정하면 A4에 135 line까지 출력됨
" set printfont=굴림체:h5
" set popt=syntax:n,number:y,left:0pc,top:1pc 
"--------------------- 
" edit by ftp
" :e ftp://10.1.8.1//devel/sip-1.4/sip/ua/wsUI/debug.cxx 
" :Nread
" :Nwrite
"--------------------- 
" line number 붙이기
" :%s/^/\=line('.').'^I'/ 
"--------------------- 
" rot13
" g?
"--------------------- 
" A file that matches with one of these patterns is ignored when completing
" file or directory names.
" :set wildignore=*.o,*.obj
"--------------------- 
"# Operate command over multiple files 
":argdo %s/foo/bar/ 
":bufdo %s/foo/bar/ 
":windo %s/foo/bar/
"--------------------- 
" -	vim: Read file from stdin
"ls | gvim -   : edit a PIPE!! "
"--------------------- 
" [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Internet Explorer\View Source Editor\Editor Name] 
" "C:\\vim\\vim60\\gvim.exe" 
"--------------------- 
" edit register repeat
" :h 10.1 참고
"--------------------- 
" comment시 자동으로 *붙이기
" 'formatoptions
"--------------------- 
" load color scheme 
" colo 
"--------------------- 
" update Help file tag
" :helptags $vim/vim70/doc
"--------------------- 
"Rename files
"help rename-files
"
"	$ vim
"	:r !ls *.c
"	:%s/\(.*\).c/mv & \1.bla
"	:w !sh
"	:q!
"--------------------- 
"exu[sage]: show help on Ex commands.
"viu[sage]: show help on Normal mode commands.
"--------------------- 
"man page
" man keyword | ul -l | vim -
"--------------------- 
"trim blank help usr_12.txt
" :%s/\s\+$//
"--------------------- 
" set restorescreen
" When set, the screen contents is restored when exiting Vim.  This also
"--------------------- 
"#substitution  http://www.vim.org/tips/tip.php?tip_id=305
":%s/\r//g                   : Delete DOS returns ^M 
":s/\(.*\):\(.*\)/\2 :  \1/  : reverse fields separated by : 
"# delete multiple duplicate lines
":%s/^\(.*\)\n\1/\1/g  
":%s/^\(.*\)\n\(\1\n\)*/\1<NL>/ 
"
"# non-greedy matching \{-} 
":%s/^.\{-}pdf/new.pdf/ 
"--------------------- 
" useful options
"set cursorline
"set cp
"set more
"--------------------- 
"Visual Studio 
"--servername srcedit --remote-tab-silent +$(CurLine) $(ItemPath)
"--------------------- 
"--------------------- 
"--------------------- 
"-----------------------------------------------------------------
" PLUGIN
" :Tlist 			[taglist.vim] : tag list
" :call colorsel 	[colorsel.vim]: color selection
" :Calendar 		[calendar.vim]: calendar
" :call ToggleSketch() [sketch.vim]: mouse sketch
" :TOhtml 			[tohtml.vim]: make html file
" \te				[tetris.vim]: tetris game
"
" \mt				[showmarks.vim]: visually displays the location of
" marks(not recommend)
" :CppComplete :CppCompleteCancel [cppomnicomplete.vim]: cpp complete

set nocompatible
if has("gui_win32")
	source $VIMRUNTIME/vimrc_example.vim
	source $VIMRUNTIME/mswin.vim

	" cygwin 설치호 HOME환경변수 때문에 viminfo파일을 저장 못하는 문제
	" 를 gvim에서 해결하기 위해 추가
	let $HOME='d:\\temp2'

	set shell=c:\windows\system32\cmd.exe
	set shellcmdflag=/C
	set lines=40
	set columns=115
	set guioptions=ga

	" from default _vimrc on Windows 
set diffexpr=MyDiff()
function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  let eq = ''
  if $VIMRUNTIME =~ ' '
    if &sh =~ '\<cmd'
      let cmd = '""' . $VIMRUNTIME . '\diff"'
      let eq = '"'
    else
      let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
    endif
  else
    let cmd = $VIMRUNTIME . '\diff'
  endif
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3 . eq
endfunction
endif


set fileencoding=korea

set sm
set hls
set ai
set ic
set incsearch
set cindent
set sw=4
"set smartindent
set path=**
set ruler

"set nowrapscan
"set guifont=굴림체:h10
"set autochdir "현재 windows gvim 6.2에서는 동작안함
"set guifont=FixedSys
set nu
set ts=4
set equalalways!
set backup!
set mouse=nvc
"set cpoptions+=t
set browsedir=current
set tags=./tags
"alternate format to be used for a status line
set statusline=%f\ %M[%n\]
"when not empty, string to be used for the window title
set titlestring=%f\ %M[%n\]
"list of pairs that match for the "%" command (local to buffer)
set matchpairs=(:),{:},[:],<:>
"command-line completion show a list of maches
"이 옵션설정시 list가 많으면 초기 반응이 느려진다.
set wildmenu

"set wrapscan!

syn on
"map ++ :let &tags = expand("%:p:h") . "/tags" <CR> :set tags? <CR>
map ++ :let &tags = getcwd()."/tags" <CR> :set tags? <CR>
map ' `
map # *N
map ,ls :ls<CR>:b
"map "" :let @/="" <CR>
map "" :nohlsearch <CR>

"--------------------- etc -B
func DeleteDuplciateWord()
	"execute '%s/^\(.*\)\n\(\1\n\)*/\1/g'
	execute '%s/^\(.*\)\n\1/\1/g'
	execute "wq!"
endfunc

com DeleteDuplciateWord call DeleteDuplciateWord()
"--------------------- etc -E

"--------------------- session -B
" _s : session operations
if has("gui_win32")
	map ,sm :mksession! $VIM/session/
	map ,ss :source $VIM/session/
else
	map ,sm :mksession! ~/vimsession/
	map ,ss :source ~/vimsession/
endif
"--------------------- session -E

"set sessionoptions-=options
set sessionoptions+=winpos

"----------- split window  -B
map sh :wincmd h <CR> :wincmd \|<CR>
map sj :wincmd j <CR> :wincmd _<CR>
map sk :wincmd k <CR> :wincmd _<CR>
map sl :wincmd l <CR> :wincmd \|<CR>
map sm :wincmd _ <CR>
map ss <c-w><c-w>
"set splitbelow
"----------- split window  -E

"visual-search
vmap * y/<C-R>"<CR> 

func ToggleFile()
	let fex = expand("%:e")
	if (fex == "h" || fex == "hxx" || fex == "hpp")
		let filenameCandi1 = expand("%:p:r").".cpp"
		let filenameCandi2 = expand("%:p:r").".cxx"
		let filenameCandi3 = expand("%:p:r").".c"
		let filenameCandi4 = expand("%:p:r").".cc"

		if (1 == filereadable(filenameCandi1))
			execute "e ".filenameCandi1
		elseif (1 == filereadable(filenameCandi2))
			execute "e ".filenameCandi2
		elseif (1 == filereadable(filenameCandi3))
			execute "e ".filenameCandi3
		elseif (1 == filereadable(filenameCandi4))
			execute "e ".filenameCandi4
		endif

	elseif (fex == "cxx" || fex == "cpp" || fex == "c" || fex == "cc")
		let filenameCandi1 = expand("%:p:r").".h"
		let filenameCandi2 = expand("%:p:r").".hxx"
		let filenameCandi3 = expand("%:p:r").".hpp"

		if (1 == filereadable(filenameCandi1))
			execute "e ".filenameCandi1
		elseif (1 == filereadable(filenameCandi2))
			execute "e ".filenameCandi2
		elseif (1 == filereadable(filenameCandi3))
			execute "e ".filenameCandi3
		endif
	endif

endfunc

"--------------------- File -B
map __ :cd %:p:h<CR>
"map == :cd D:\work_sumsung\samsungkp<CR>
"map == :cd D:\work\etri\UserAgent<CR>
"map == :cd D:\workce\KT3100\3100SIP <CR>
map gF :call ToggleFile() <CR>
map gsF :let @/ = expand("<cword>") <CR> :sp <CR> :call ToggleFile() <CR>
map ,b : browse e <CR>
"--------------------- File -E

"map W : !python D:\utils\vimutils\w.py <cword> <CR>

"--------------------- highlight -B
if has("gui_win32")
	highlight Nontext 	guibg=black 	guifg=white 
	"highlight constant	guifg=brown
	highlight Normal 	guifg=white 	guibg=black 	font=FixedSys
	highlight Search 	guifg=white 	guibg=red ctermbg=red
	"highlight comment 	guifg=gray
	"highlight statement guifg=magenta
	highlight todo 		guibg=black
	highlight LineNr	guifg=lightgreen
	highlight WildMenu	guifg=white guibg=blue ctermfg=white ctermbg=blue
	"IME가 on 되었을때
	highlight CursorIM	guibg=green

else
"	highlight Nontext 	ctermbg=black 	ctermfg=white 
"	highlight Normal 	ctermfg=white 	ctermbg=black 	font=FixedSys
"	highlight Search 	ctermfg=white 	ctermbg=red ctermbg=red
"	highlight todo 		ctermbg=black
"	highlight LineNr	ctermfg=lightgreen
"	highlight WildMenu	ctermfg=white ctermbg=blue ctermfg=white ctermbg=blue
"	"IME가 on 되었을때
"	highlight CursorIM	ctermbg=green
endif
"--------------------- highlight -B

"map 젨 :simalt ~<CR>
"map <M-Space> :simalt ~<CR>

"--------------------- grep -S 
set grepprg=grep\ -n

let $oldpattern = "*.cpp"

func GrepInFind()
	echo 'word: '.expand("<cword>")
	let pattern = input("files (default:".$oldpattern."): ")

	if (strlen(pattern) <= 0)
		if (strlen($oldpattern) <= 0)
			return 
		else
			let pattern = $oldpattern
		endif
	else
		let $oldpattern = pattern
	endif

if has("gui_win32") " if window

	let fpath="!c:\\cygwin\\bin\\ff"
	"let tempFilePath = tempname()
	let tempFilePath = expand('~').'\f.txt'
	exec fpath.' -name \'.pattern.' | xargs grep -Hwn '.expand("<cword>").' > '.'"'.tempFilePath.'"'

else "if unix

	let fpath="!find"
	"let tempFilePath = tempname()
	let tempFilePath = expand('~').'/f.txt'
	exec fpath.' -L . -name \'.pattern.' | xargs grep -Hwn '.expand("<cword>").' > '.'"'.tempFilePath.'"'

endif


	if 0 < getfsize(tempFilePath)
		exec ':cf '.tempFilePath
		exec ':cl!'
	else
		echo "--------------------"
		echo "no list"
	endif

endfunc

func GrepInFindWithKey()
	let keyPattern = input("Key Pattern (default:".$oldkeyPattern."): ")

	if (strlen(keyPattern) <= 0)
		if (strlen($oldkeyPattern) <= 0)
			return
		else
			let keyPattern = $oldkeyPattern
		endif
	else
		let $oldkeyPattern = keyPattern
	endif

	echo 'Key Pattern: '.keyPattern

	let pattern = input("files (default:".$oldpattern."): ")

	echo  "\n\r"

	if (strlen(pattern) <= 0)
		if (strlen($oldpattern) <= 0)
			return 
		else
			let pattern = $oldpattern
		endif
	else
		let $oldpattern = pattern
	endif

if has("gui_win32") " if window

	let fpath="!c:\\cygwin\\bin\\ff"
	"let tempFilePath = tempname()
	let tempFilePath = expand('~').'\f.txt'
	exec fpath.' -name \'.pattern.' | xargs grep -Hwn '.keyPattern.' > '.'"'.tempFilePath.'"'

else "if unix

	let fpath="!find"
	"let tempFilePath = tempname()
	let tempFilePath = expand('~').'/f.txt'
	exec fpath.' -L . -name \'.pattern.' | xargs grep -Hwn '.KeyPattern.' > '.'"'.tempFilePath.'"'

endif

	if 0 < getfsize(tempFilePath)
		exec ':cf '.tempFilePath
		exec ':cl!'
	else
		echo "--------------------"
		echo "no list"
	endif

endfunc

map ,gf :call GrepInFind() <CR>
map ,gF :call GrepInFindWithKey() <CR>
"map _gg :exe "grep -n <cword> *.".expand("%:e") <CR> : cl! <CR>
map ,gg :exe "grep -n -w <cword> *.h *.hxx *.hh *.c *.cc *.cpp *.cxx"<CR> : cl! <CR>
map ,gG :exe "grep -n -r -w <cword> ."<CR> : cl! <CR>
"--------------------- grep -E 

"--------------------- List -B
map cl : cl!<CR>
map cn : cn<CR>
map cp : cp<CR>
map cw : cw <CR>
"--------------------- List -E


"" comment.vim
"let Author="seesun"
"vmap +d :call CommentCBlock() <CR>
"vmap -d :call UnCommentCBlock() <CR>
"vmap ++d :call CommentCBlockWithComment() <CR>
"
"" comments.vim
"" key-mappings for comment line in normal mode
"noremap  +D :call CommentLine()<CR>
"" key-mappings for range comment lines in visual <Shift-V> mode
"vnoremap +D :call RangeCommentLine()<CR>
"
"" key-mappings for un-comment line in normal mode
"noremap  -D :call UnCommentLine()<CR>
"" key-mappings for range un-comment lines in visual <Shift-V> mode
"vnoremap -D :call RangeUnCommentLine()<CR>



func FuncTD()
	"let comment = input("msg:")
	"exec 'let @0=strftime(" //-seesun- %Y.%m.%d. ") . comment'
	exec 'let @0=strftime(" //-seesun- %Y.%m.%d. ") '
	exec 'normal! $"0p'
endfunc

func InsertCurTime()
	exec 'let @0=strftime("------------------------------\n@ %c \n")'
	exec 'normal! $"0p'
endfunc

"map _td : exec 'let @0=strftime(" //-dong- %Y.%m.%d.")\|normal! $"0p'<CR>
map ,td : call FuncTD() <CR>
"map _tD : exec 'let @0=strftime("//-dong- %Y.%m.%d. ")\|normal! ^"0P'<CR>
map ,tD : exec 'let @0="//-dong- "\|normal! ^"0P'<CR>
map ,tb : exec 'let @0="// 6PM8PL_START GlobalPopup"\|normal! ^"0P'<CR>
map ,te : exec 'let @0="// 6PM8PL_END "\|normal! ^"0P'<CR>
map ,T : call InsertCurTime() <CR>

map ,F o<ESC>i/* <ESC>a*<ESC>80.o<ESC>a <ESC>a*<ESC>77.a */<ESC>ko
map ,f o/**@brief@param@return<ESC>a/<ESC>kkk<ESC>
" ----------- comment - E ----------

"----------- My Syntax Highlight - S ----------
"my syntax highlight
highlight hh1 guibg=blue ctermbg=blue
highlight hh2 guibg=darkgreen ctermbg=darkgreen ctermfg=black
"highlight hhclassMember guibg=black guifg=#7ff4f8 gui=undercurl guisp=red
highlight hhclassMember guibg=black guifg=orange gui=undercurl guisp=red
highlight 1MatchColor guibg=lightred guifg=black
highlight 2MatchColor guibg=#f3dd7f guifg=black
highlight 3MatchColor guibg=#ffff2f guifg=black

map ,ha :call AddKeyword(1) <CR>
map ,hb :call AddKeyword(2) <CR>
map ,hm :call AddKeyword(3) <CR>

map ,hda :call DelKeyword(1) <CR>
map ,hdb :call DelKeyword(2) <CR>
map ,hdm :call DelKeyword(3) <CR>

map ,hcc :syntax clear hh1 hh2 hhclassMember<CR>
map ,hcv :syntax clear hh1 hh2<CR> :let @x="" <CR> :let @y="" <CR>
map ,hcm :syntax clear hhclassMember<CR> :let @z="" <CR> 

map ,hh :syntax clear hh1 hh2<CR> :execute 'syntax keyword hh1 ' . @x <CR> :execute 'syntax keyword hh2 ' . @y<CR>

"map ,hq :exec 'call MultipleSearch("'.expand("<cword>").'")' <CR>
"map ,hcq :SearchReset <CR>

"map ,h1 :execute 'match MatchColor /\<'.expand("<cword>").'\>/' <CR>
"map ,hc1 :match <CR>

map ,h1 :call AddKeywordForMatch(1) <CR>
map ,hd1 :call DelKeywordForMatch(1) <CR>
map ,hc1 :call ClearMatch(1) <CR>

map ,h2 :call AddKeywordForMatch(2) <CR>
map ,hd2 :call DelKeywordForMatch(2) <CR>
map ,hc2 :call ClearMatch(2) <CR>

map ,h3 :execute '3match 3MatchColor /\<'.expand("<cword>").'\>/' <CR>
map ,hc3 :3match <CR>

map ,h0 :call ClearMatch(0) <CR>
map ,h9 :call ShowMatch(0) <CR>
map ,h8 :call ShowMatch(1) <CR>

let Match1Keyword='TODO'
let Match2Keyword='TODO'


func ShowMatch(b)
	if (a:b == 0)
		execute '1match'
		execute '2match'
	else
		execute '1match 1MatchColor /'. g:Match1Keyword .'/'
		execute '2match 2MatchColor /'. g:Match2Keyword .'/'
	endif

endfunc

func ClearMatch(i)
	if (a:i == 1 || a:i == 0)
		let g:Match1Keyword='TODO'
		execute '1match'
	endif
	if (a:i == 2 || a:i == 0)
		let g:Match2Keyword='TODO'
		execute '2match'
	endif

	if (a:i == 0) 
		execute '3match'
	endif
endfunc

func AddKeywordForMatch(i)
	let hhTemp = '\|\<' . expand("<cword>") .'\>'

	if (a:i == 1)
		let g:Match1Keyword .=  hhTemp
		execute '1match 1MatchColor /'. g:Match1Keyword .'/'
	endif

	if (a:i == 2)
		let g:Match2Keyword .=  hhTemp
		execute '2match 2MatchColor /'. g:Match2Keyword .'/'
	endif

endfunc

func DelKeywordForMatch(i)
	let hhTemp = '\\|\\<'. expand("<cword>") .'\\>'
	if (a:i == 1)
		let g:Match1Keyword = substitute(g:Match1Keyword, hhTemp , "", "") 
		if g:Match1Keyword!= ""
			execute '1match 1MatchColor /'. g:Match1Keyword .'/'
		else
			execute '1match'
		endif
	endif

	if (a:i == 2)
		let g:Match2Keyword = substitute(g:Match2Keyword, hhTemp , "", "") 
		if g:Match2Keyword!= ""
			execute '2match 2MatchColor /'. g:Match2Keyword .'/'
		else
			execute '2match'
		endif
	endif
endfunc

func AddKeyword(i)
	let hhTemp = " " . expand("<cword>")
	if (a:i == 1)
		execute 'syntax keyword hh1 ' . hhTemp
		let @x = @x . hhTemp
	elseif (a:i == 2)
		execute 'syntax keyword hh2 ' . hhTemp
		let @y = @y . hhTemp
	elseif (a:i == 3)
		execute 'syntax keyword hhclassMember ' . hhTemp
		let @z = @z . hhTemp
	endif

endfunc

func DelKeyword(i)
	let hhTemp = " " . expand("<cword>")
	if (a:i == 1)
		syntax clear hh1
		let @x= substitute(@x, hhTemp , "", "") 
		if @x!= ""
			execute 'syntax keyword hh1 ' . @x 
		endif

	elseif (a:i == 2)
		syntax clear hh2
		let @y = substitute(@y, hhTemp , "", "") 
		if @y != ""
			execute 'syntax keyword hh2 ' . @y 
		endif

	elseif (a:i == 3)
		syntax clear hhclassMember
		let @z = substitute(@z, hhTemp , "", "") 
		if @z != ""
			execute 'syntax keyword hhclassMember ' . @z
		endif
	endif

endfunc

func SetMySyntaxHighlight()
	if strlen(@x) 
		execute 'syntax keyword hh1 ' . @x
	endif

	if strlen(@y) 
		execute 'syntax keyword hh2 ' . @y
	endif

	if strlen(@z) 
		execute 'syntax keyword hhclassMember ' . @z
	endif
endfunc

"func MyScript()
"	source ~/VimRuntime/comment.vim
"	source ~/VimRuntime/comments.vim
"endfunc


autocmd BufEnter * call SetMySyntaxHighlight()
"autocmd BufNewFile,BufRead * call MyScript()

"autocmd BufNewFile * cd %:p:h
"----------- My Syntax Highlight - E ----------

"----------- Windows - S -----------------------
if has("gui_win32")

func ConfigVocabulary()
	"execute("winsize 16 60") 
	execute("set cmdheight=3")
	execute("set nonu")
	execute("set columns=15")
	"execute("set lines=70")
	execute("set lines=21")
	execute("winpos 1790 806")
	"execute("winpos 0 0")
	"execute("e F:\\english\\word\\vc.txt") 
	execute("e D:\\utils\\tools\\l.txt")
	execute("cd %:p:h")
	execute("normal G")
	"nmap <Space> :call CallBsh() <CR>
	nmap N :new <CR>
	nmap Q :q! <CR>
	imap Q <ESC> :q! <CR>
	map <F4> :call CallBsh() <CR>
endfunc

func CallBsh()
	let engword = ''.expand("<cword>")
	execute("normal j")
	"execute("!start C:\\Program Files\\Microsoft Reference\\Bookshelf 2.0\\BS99KL.exe -i a")
	execute("!start bsh.exe -i ".engword)
endfunc

func ExplorerCurrentLineString()
	let currentline = line('.')
	execute 'silent !explorer.exe '.getline(currentline)
endfunc

	"map <F12> :call ExplorerCurrentLineString() <CR>

	com V1 call ConfigVocabulary()
	com V2 winpos 1542 712 | winsize 16 16 | e D:\mydoc\etc\vc.txt | $ | cd %:p:h
	com Pos winpos 2146 0 | winsize 132 67
	com Pos1 winsize 140 2 | winpos 1926 1134 
	com Pos2 winpos 168 0 | winsize 138 56

	"com  -nargs=1 H !start mh <args>
	com  -nargs=1 Ws : !start "C:\Program Files\Microsoft Reference\Bookshelf 2.0\BS99KL.exe" -i <args> <CR><CR>
	com  -nargs=1 Pronounce : !start bsh.exe -f <args> 

	autocmd GUIEnter * Pos


"map _d :exe "!docxx -p -S -H -d ".expand("%:p:h")."\\hdocs ".expand("%:p:r:t").".*"<CR><CR>
"map _D :exe "!docxx -p -S -H -d ".expand("%:p:h")."\\hdocs -I docxxlist.txt" <CR>

	map ,e :exe "!start C:\\windows\\explorer /e,".expand("%:p:h")<CR>
	map <F3> : !start "C:\Program Files\Microsoft Reference\Bookshelf 2.0\BS99KL.exe" -i <cword> <CR><CR>


endif
"----------- Windows - E -----------------------


"----------- Python - S ---------
func SetPythonCommentMap()
	map +d :s/^/# /g<CR> :let @/=histget("search",-2) <CR>
	map -d :s/^# //g <CR> let @/=histget("search",-2) <CR>
	map +D :s/^/# /g<CR> <ESC>:'< <CR> :exec 'let @0=strftime("# -dong- %m.%d.%H:%M \n")\|normal! "0P'<CR> :'> <CR>o <ESC>:exec 'let @0=strftime("# -dong- %m.%d.%H:%M ")\|normal! "0P'<CR>:let @/=histget("search",-2) <CR>
	map -D :s/^# //g<CR> :'<,'>g/-dong-/d <CR> :let @/=histget("search",-2) <CR>
endfunc

autocmd BufRead *.py call SetPythonCommentMap()

let $PW="E:\\programming\\work\\python"
"map _z :w<CR> :!C:\python22\python.exe %<CR> 
"----------- Python - E ---------

"---------------------- JAVA  -B
"map _r : !run.bat <CR>
"map _r : !java "%<" <CR>
"map _d : !javadoc -private -d ../docs "%" <CR>
"map _D : !javadoc -private -d ../docs *.java <CR>
"map cc :w <CR>:!javac -Xstdout -d ../binary "%" > err.txt <CR>: cf! err.txt <CR>: cl! <CR>
"map cC :w <CR>:!javac -Xstdout -d ../binary *.java > err.txt <CR>: cf! err.txt <CR>: cl! <CR>
"map _l :cf! err.txt <CR>: cl! <CR>
"map _c :w<CR>:!javac -Xstdout "%" > err.txt<CR>:cf! err.txt<CR>:cl!<CR>
"map _g :grep <cword> *.java > err.txt<CR>:cf! err.txt<CR>:cl!<CR>
"map _j : !java "%<" <CR>
"map _s : so !VIM/syntax/java.vim <CR>
"---------------------- JAVA  -E


augroup Binary
  au!
  au BufReadPre  *.err let &bin=1
  au BufReadPost *.err if &bin | %!xxd
  au BufReadPost *.err set ft=xxd | endif
  au BufWritePre *.err if &bin | %!xxd -r
  au BufWritePre *.err endif
  au BufWritePost *.err if &bin | %!xxd
  au BufWritePost *.err set nomod | endif
augroup END

if has("gui_win32") " if window
	language english
elseif has("unix") "if unix
	"language en_US_ISO_8859-1
	set t_Co=16
	hi LineNr ctermfg=243
	set backup!
endif

"--------------------- sign -B

"highlight default BookmarkCol guifg=black guibg=green gui=bold,underline
highlight default BookmarkCol guifg=black guibg=darkgray
sign define MyBookmark linehl=BookmarkCol  text=>>
"map _sp :exe 'sign place '.line(".").' name=MyBookmark line='.line(".").' buffer='.winbufnr(0) <CR> 
map ,sp :call AddSign() <CR>
map ,su :exe 'sign unplace ' <CR>
map ,sl :exe 'sign place' <CR>
map ,sj :exe 'sign place' \| call JumpSign() <CR>

let $CountSign = 0
func AddSign()
	let $CountSign = $CountSign + 1
	exe 'sign place '.$CountSign.' name=MyBookmark line='.line(".").' buffer='.winbufnr(0)
endfunc

func JumpSign()
	let id = input('sign id: ')
	if (0 < strlen(id))
		let  filename= input('file: ')
		if (0 < strlen(filename))
			execute 'sign jump '.id.' buffer='.bufnr(filename)
		else
			"echo 'current file'
			execute 'sign jump '.id.' buffer='.winbufnr(0)
		endif
	else
		echo 'no operation'
	endif
endfunc
"--------------------- sign -E


"--------------------- WORK -E 


"--------------------- CPP Enhanced Syntax -S
"from vim.org - Tips
highlight  CPPMethod gui=underline guifg=#0095cc 
function! EnhanceCppSyntax() 
    syn match cppFuncDef "::\~\?\zs\h\w*\ze([^)]*\()\s*\(const\)\?\)\?$" 
    highlight def link cppFuncDef CPPMethod
endfunction 
autocmd Syntax cpp call EnhanceCppSyntax() 
"--------------------- CPP Enhanced Syntax -E

"--------------------- for windows Printing -S 
" A4 135 lines
com Ps echo "135 lines" | set printfont=굴림체:h5 |  set popt=syntax:n,number:y,left:0pc,top:1pc | set printfont? popt?
"
" A4 83 lines
com Ps2 echo "83 lines" | set printfont=굴림체:h8 |  set popt=syntax:n,number:y,left:0pc,top:1pc | set printfont? popt?
"--------------------- for windows Printing -E 

"--------------------- insert, normal mode 전환시 한영자동전환 -B
"--------------------- insert, normal mode 전환시 한영자동전환 -E
"
"--------------------- cscope	-B
highlight ModeMsg guibg=black guifg=green

" add general cscope config from sourceforge
source ~/.vim/plugin/cscope_maps.vim

com CscopeAddDB cscope add cscope.out 
com CscopeKillAll cscope kill *

func MakeCScopeDB()
	execute "cscope kill *"
	execute "!rm cscope.out"
	let AbsPath = getcwd()
if has("gui_win32") " if window
	"execute '!ff . -name \*.h -o -name \*.hh -o -name \*.cpp -o -name \*.cxx -o -name \*.c > srclist.txt'
	execute '!ff '.AbsPath.' -name \*.h -o -name \*.hh -o -name \*.cpp -o -name \*.cxx -o -name \*.c > srclist.txt'
else
	execute '!find -L . -name \*.h -o -name \*.hh -o -name \*.cpp -o -name \*.cxx -o -name \*.c > srclist.txt'
endif
	execute '!cscope -R -b -i srclist.txt'
endfunc

com CscopeMakeDB call MakeCScopeDB()
"--------------------- cscope	-E
"--------------------- cppomnicomplete.vim -B
set nocp
filetype plugin on
map <C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q . <CR>

func CancelCppComplete()
	execute "iunmap <expr> ."
	execute "iunmap <expr> >"
	set omnifunc=cppomnicomplete#Complete
endfunc

com CppComplete set omnifunc=cppomnicomplete#Complete | inoremap <expr> . cppomnicomplete#MayCompleteDot() | inoremap <expr> > cppomnicomplete#MayCompleteArrow()
" because of any bug. make CancelCppComplete()
com CppCompleteCancel call CancelCppComplete() 
"--------------------- cppomnicomplete.vim -E
"--------------------- Media Player -B
func MediaColor(color)
	execute "highlight Normal guibg=" . a:color
	execute "highlight Nontext guibg=" . a:color
endfunc

map <C-Space> :call MediaColor('black') <CR>
com ColorMedia call MediaColor('#100010')
com ColorK call MediaColor('#0F000F')
"--------------------- Media Player -E
"--------------------- tab -B
" V7.0
if 700 <= v:version
	map <C-Tab> gt
	map <C-S-Tab> gT
	"set guioptions +=e
	"set guitablabel=%t
	highlight TabLineSel guifg=green gui=NONE
	highlight TabLineFill guifg=black
endif
"--------------------- tab -E
"--------------------- Windows CE .Net -B
autocmd BufRead sources :set ft=make
autocmd BufRead *.reg :set ft=dosini
"--------------------- Windows CE .Net -E
"--------------------- Tlist -B
let Tlist_Use_Right_Window=1
map st :TlistOpen <CR>
hi FoldColumn guibg=black
hi TagListFileName guifg=black
"--------------------- Tlist -E

"--------------------- tag -B
map tn : tn<CR>
map tp : tp<CR>
"--------------------- tag -E
"--------------------- Temp -B
" func LinkFormat()
" 	execute "%s/\\([0-9]\\{1,3}\\).*/mv & \\1.txt"
" 	execute "%s/&/'&'/g"
" 	execute "set ff=unix"
" endfunc
" com LFormat call LinkFormat()
" map <F11> :let @* = "[ ".expand("%:p")." ]" <CR>
abb #i #include

com EntryFormatting :%s;</\a\+>;&;g

func FormatingForvate()
	execute "%s;</\\a\\+>;&;g"
	execute "%s/<Entry>/&/g"
	execute "%s/<\\/Entry>/&/g"
	execute "set encoding=UTF-8"
endfunc


"--------------------- Temp -E

"--------------------- cygwin -B
map ,z :! a.exe <CR>
"--------------------- cygwin -E
"--------------------- abbreviate for STL -B
abbreviate <expr> vii ABB_iterator("vector")

function ABB_iterator(container)
	call inputsave()

	let type = input("Type:")
	let valuable = input("Valuable:","","tag")

	call inputrestore()
	
	let code = a:container.'<'.type.'>::iterator it 	= '.valuable.'.begin();'
	let code .= a:container.'<'.type.'>::iterator itEnd = '.valuable.'.end();'
	let code .= 'for ( ; it != itEnd; it++) {'

	return code
endfunc

"--------------------- -E
autocmd BufEnter FavoriteM.asx call FormatingForvate()
autocmd BufEnter Favorite.asx call FormatingForvate()
"--------------------- -B
func DeleteDuplicateBlankLiine()
	execute "%s/^\(.*\)\n\1/\1/g"
endfunc
"--------------------- -E
"--------------------- Android -B
autocmd BufRead *.aidl :set ft=idl
"--------------------- Android-E

"--------------------- SimpleDiff -B
function SimpleDiff()
	let FilePath = getline(line("."))
	let AFullPath = $Aroot.FilePath
	let BFullPath = $Broot.FilePath

	execute("sp")
	execute("wincmd _")
	execute("e " . BFullPath)
	execute("diffthis")

	execute("vnew")
	execute("e " . AFullPath)
	execute("diffthis")

	echo "A file: " . AFullPath
	echo "B file: " . BFullPath
endfunc

function SimpleDiffOn()
	map ra : let $Aroot = expand("%:p:h") . "/" \| echo "A Root: " . $Aroot <CR>
	map rb : let $Broot = expand("%:p:h") . "/" \| echo "B Root: " . $Broot <CR>

	map di : call SimpleDiff() <CR>
	map do : diffoff! \| q \| q <CR>
	map dv : echo "A Root: " . $Aroot \| echo "B Root: " . $Broot <CR>
endfunc

"--------------------- SimpleDiff -E
com Jflist :new ~/worktablet/p980_k32_1019/jflist.txt | map <buffer> <CR> gf
com Jhlist :new ~/worktablet/v909_v10a_pre4_HRI55/jhlist.txt | map <buffer> <CR> gf
com Chlist :new ~/worktablet/v909_v10a_pre4_HRI55/chlist.txt | map <buffer> <CR> gf

com TSurfaceFlinger :cd /work1/donghyuk.kim/worktablet/v909_v10a_pre4_HRI55/android/frameworks/base/ | set tags=/work1/donghyuk.kim/worktablet/v909_v10a_pre4_HRI55/android/frameworks/base/tags_surfaceflinger 
set expandtab

hi LineNr ctermfg=10

hi Comment ctermfg=6
hi Directory ctermfg=yellow
hi Visual ctermbg=cyan
