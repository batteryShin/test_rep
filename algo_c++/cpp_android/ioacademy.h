// Module	 : ioacademy.h
// author	 : 강석민
// mail		 : smkang @ ioacademy.co.kr
// home page : www.ioacademy.co.kr
//			   cafe.naver.com/cppmaster

#ifndef IOACADEMY_H
#define IOACADEMY_H

#if _MSC_VER > 1000
#pragma  once
#endif

#ifdef UNICODE
#undef _UNICODE
#undef UNICODE
#endif

#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <tchar.h>
using namespace std;

namespace ioacademy
{
	namespace basic
	{
		int _nextInt()
		{
			static int n = 0;
			++n;
			return n;
		}
		void IoSetCursor(int x, int y )
		{
			COORD coord = { x, y};
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE), coord);
		}
		class Color
		{
			int _red, _green, _blue;
		public:
			Color( int r = 0, int g = 0, int b = 0 ) : _red(r), _green(g), _blue(b) {}
			inline int red()   const { return _red; }
			inline int green() const { return _green; }
			inline int blue()  const { return _blue; }
			inline static Color& redColor()
			{
				static Color red(255,0,0);
				return red;
			}
			inline static Color& greenColor()
			{
				static Color green(0,255,0);
				return green;
			}
			inline static Color& blueColor()
			{
				static Color blue(0,0,255);
				return blue;
			}
		};
	}
	namespace message
	{
		void IoProcessMessage()
		{
			MSG msg;
			while( GetMessage( &msg , 0, 0, 0)  )
			{
				TranslateMessage( &msg);
				DispatchMessage(&msg);
			}
		}
	
	#ifdef AUTO_MESSAGE_LOOP
		class __GlobalMessageLoop
		{
		public:
			__GlobalMessageLoop()  { srand(time(0));	}
			~__GlobalMessageLoop() { IoProcessMessage();}
		} _messageLoop;
	#endif
	}
	namespace timer
	{
		typedef void (*IO_TIMER_HANDLER)(int);
		IO_TIMER_HANDLER user_timer_handler = 0;

		int CALLBACK _InternalTimerProcedure( HWND hwnd, UINT msg, UINT_PTR id, DWORD )
		{
			if ( user_timer_handler )
				user_timer_handler( id );
			return 0;
		}

		int IoSetTimer(int ms, IO_TIMER_HANDLER handler )
		{
			user_timer_handler = handler;

			int id = SetTimer(0, 0, ms, (TIMERPROC)_InternalTimerProcedure);

			return id;
		}

		void IoKillTimer( int id )
		{
			KillTimer( 0, id );
		}
	}
	namespace gui 
	{
		typedef int (*IO_MESSAGE_HANDLER)(int, int, int, int);

		IO_MESSAGE_HANDLER user_message_handler = 0;

		LRESULT CALLBACK _InternalMessageProcedure( HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
		{
			if ( user_message_handler )
				user_message_handler((int)hwnd, msg, wp, lp);
	
			if ( msg == WM_DESTROY)
			{
				ExitProcess(0);
				//PostQuitMessage(0);
			}
			return DefWindowProc( hwnd, msg, wp, lp );
		}

		//----------------------------------------------------------------------------------------------
		int IoMakeWindow( IO_MESSAGE_HANDLER proc, string title = "S/W Design Pattern(C++)")
		{
			user_message_handler = proc;

			WNDCLASS wc = {0};
			wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
			wc.hCursor       = LoadCursor(0, IDC_ARROW);
			wc.hIcon		 = LoadIcon( 0, IDI_WINLOGO);
			wc.hInstance     = (HINSTANCE)GetModuleHandle(0);
			wc.lpfnWndProc   = _InternalMessageProcedure;

			ostringstream oss;
			oss << "IO_GUI" << basic::_nextInt();

			string cname = oss.str();
			wc.lpszClassName = cname.c_str();
			RegisterClass(&wc);

			HWND hwnd =  CreateWindow(cname.c_str(), title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 0, 0, 0,0);
	
			ShowWindow( hwnd, SW_SHOW);
			return (int)hwnd;
		}

		void IoSetWindowRect( int handle, int x, int y, int w, int h)
		{
			MoveWindow( (HWND)handle, x, y, w, h, TRUE);
		}

		void IoAddChild( int parent_handle, int child_handle)
		{
			SetWindowLong( (HWND)child_handle, GWL_STYLE, WS_VISIBLE | WS_BORDER | WS_CHILD  );
			SetParent( (HWND)child_handle, (HWND)parent_handle);
		}

		void IoSetWindowColor( int handle, const basic::Color& color )
		{
			HBRUSH brush = CreateSolidBrush( RGB(color.red(), color.green(), color.blue()));
			HBRUSH old = (HBRUSH)SetClassLong( (HWND)handle, GCL_HBRBACKGROUND, (LONG)brush);
			DeleteObject( old ); 
			InvalidateRect( (HWND)handle, 0, TRUE);
		}
	}
	namespace module
	{
		#ifdef _WIN32
		#define IOEXPORT __declspec(dllexport)
		#else
		#define IOEXPORT 
		#endif

		void* IoLoadModule(string path )
		{
			return reinterpret_cast<void*>(LoadLibraryA( path.c_str() ));
		}
		void IoUnloadModule( void* p)
		{
			FreeLibrary( (HMODULE)p );
		}
		void* IoGetFunctionAddress( void* module, string func)
		{
			return reinterpret_cast<void*>(GetProcAddress( (HMODULE)module, func.c_str()));
		}
	}
	namespace file
	{
		typedef int (*PFENUMFILE)(string, void*);

		void IoEnumFiles( string path, string filter, PFENUMFILE f, void* param)
		{
			BOOL b = SetCurrentDirectory(path.c_str());

			if ( b == false )
			{
				cout << "[DEBUG] " << path.c_str() << " directory does not exit" << endl;
				return;
			}
			WIN32_FIND_DATA wfd = {0};
			HANDLE h = ::FindFirstFile( filter.c_str(), &wfd);
			do
			{
				if ( !(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && !(wfd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN ))
				{
					if ( f( wfd.cFileName, param )  == 0 ) break;
				}
			}
			while( FindNextFile( h, &wfd) );

			FindClose(h);
		}
	}
	namespace thread
	{
		class IoMutex
		{
			HANDLE hMutex;
		public:
			inline IoMutex( string name = "" ) : hMutex(CreateMutex( 0, 0, name.c_str())) {}
			inline ~IoMutex() { CloseHandle( hMutex ); }

			inline void Lock()   { WaitForSingleObject( hMutex, INFINITE); }
			inline void Unlock() { ReleaseMutex( hMutex);}
		};

		template<typename T> class IoScopedLock
		{
			T& sync;
		public:
			inline IoScopedLock(T& o, bool autolock = true) : sync(o) { if ( autolock) sync.Lock(); }
			inline ~IoScopedLock() { sync.Unlock(); }
			inline void Lock() { sync.Lock(); }
			inline void Unlock() { sync.Unlock(); }
		};
	}
	namespace ipc
	{
		typedef int(*IPC_SERVER_HANDLER)(int, int, int);

		IPC_SERVER_HANDLER _proxyServerHandler;

		LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
		{
			if ( msg >= WM_USER )
					return _proxyServerHandler( msg - WM_USER, wParam, lParam);

			switch( msg )
			{
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;
			}
			return DefWindowProc( hwnd, msg, wParam, lParam);
		}

		HWND MakeWindow( string name, int show )
		{
			HINSTANCE hInstance = GetModuleHandle(0);
			WNDCLASS wc;
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.hbrBackground = (HBRUSH)GetStockObject( WHITE_BRUSH );
			wc.hCursor = LoadCursor( 0, IDC_ARROW);
			wc.hIcon   = LoadIcon( 0, IDI_APPLICATION);
			wc.hInstance    = hInstance;
			wc.lpfnWndProc  = WndProc;
			wc.lpszClassName= _T("First");
			wc.lpszMenuName = 0;
			wc.style		= 0;

			RegisterClass( &wc ); 

			HWND hwnd = CreateWindowEx( 0,	_T("First"), name.c_str() , WS_OVERLAPPEDWINDOW,
										CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,	0, 0, hInstance, 0); 

			ShowWindow( hwnd, show ); 
			return hwnd;
		}


		void ProcessMessage( IPC_SERVER_HANDLER handler)
		{
			_proxyServerHandler = handler;
			MSG msg;
			while( GetMessage( &msg, 0, 0, 0) ) 
			{
				TranslateMessage( &msg ),
				DispatchMessage(&msg);
			}
		} 
		//------------------------------------------------------------------
		void IoStartServer( string name, IPC_SERVER_HANDLER handler, int show = SW_HIDE )
		{
		#ifdef _DEBUG
			printf("[DEBUG] %s Server Start...\n", name.c_str());
		#endif

			MakeWindow(name, show);
			ProcessMessage(handler);
		}

		int IoFindServer( string name )
		{
			HWND hwnd = FindWindow( 0, name.c_str() );

			if ( hwnd == 0 ) 
			{
				printf("[DEBUG] 실패 : %s Server를 찾을수 없습니다.\n", name.c_str());
				return -1;	
			}
			return (int)hwnd;
		}

		int IoSendServer( int serverid, int code, int param1, int param2 )
		{
			return SendMessage( (HWND)serverid, code + WM_USER, param1, param2);
		}
		////////////////////////////////////////
		// for android
		/*
		int get_service( string name )
		{
			HWND hwnd = FindWindow( 0, name.c_str() );

			if ( hwnd == 0 ) 
			{
				printf("[DEBUG] 실패 : %s Server를 찾을수 없습니다.\n", name.c_str());
				return -1;	
			}
			return (int)hwnd;
		}

		void add_service( string name )
		{
		#ifdef _DEBUG
			printf("[DEBUG] %s Service register\n", name.c_str());
		#endif

			MakeWindow(name, SW_HIDE);
		}

		int binder_call( int fd, int* msg, int* reply, int serverid, int code)
		{
			if ( serverid == 0 )
			{
				if ( code == SVC_MGR_CHECK_SERVICE )
				{
					return get_service( reinterpret_cast<const char*>(msg));
				}
				else if ( code == SVC_MGR_ADD_SERVICE )
				{
					add_service( reinterpret_cast<const char*>(msg) );
					return 0;
				}
			}
			return SendMessage( (HWND)serverid, code + WM_USER, *msg, *reply);
		}

		void binder_loop( int fd, HANDLER handler )
		{
			ProcessMessage(handler);
		}

		int binder_open( int size)
		{
			// open() system call을 사용해서 바인더 드라이버를 오픈
			// mmap()으로 shared memory 생성
			return rand() % 10000;
		}
		*/
	}
	using namespace basic;
	using namespace message;
	using namespace timer;
	using namespace gui;
	using namespace module;
	using namespace file;
	using namespace thread;
	using namespace ipc;
}

#endif	// IOACADEMY_H
