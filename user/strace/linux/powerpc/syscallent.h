/*
 * Copyright (c) 1993 Branko Lankester <branko@hacktic.nl>
 * Copyright (c) 1993, 1994, 1995 Rick Sladkey <jrs@world.std.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *	$Id: syscallent.h,v 1.7 2001/08/03 12:27:54 wichert Exp $
 */

	{ 5,	0,	printargs,		"SYS_0"			}, /* 0 */
	{ 1,	TP,	sys_exit,		"exit"			}, /* 1 */
	{ 0,	TP,	sys_fork,		"fork"			}, /* 2 */
	{ 3,	TF,	sys_read,		"read"			}, /* 3 */
	{ 3,	TF,	sys_write,		"write"			}, /* 4 */
	{ 3,	TF,	sys_open,		"open"			}, /* 5 */
	{ 1,	0,	sys_close,		"close"			}, /* 6 */
	{ 3,	TP,	printargs,		"waitpid"		}, /* 7 */
	{ 2,	TF,	printargs,		"creat"			}, /* 8 */
	{ 2,	TF,	sys_link,		"link"			}, /* 9 */
	{ 1,	TF,	sys_unlink,		"unlink"		}, /* 10 */
	{ 3,	TF|TP,	sys_execve,		"execve"		}, /* 11 */
	{ 1,	TF,	sys_chdir,		"chdir"			}, /* 12 */
	{ 1,	0,	sys_time,		"time"			}, /* 13 */
	{ 3,	TF,	sys_mknod,		"mknod"			}, /* 14 */
	{ 2,	TF,	sys_chmod,		"chmod"			}, /* 15 */
	{ 3,	TF,	printargs,		"lchown"		}, /* 16 */
	{ 5,	0,	printargs,		"break"			}, /* 17 */
	{ 2,	TF,	sys_stat,		"oldstat"		}, /* 18 */
	{ 3,	TF,	sys_lseek,		"lseek"			}, /* 19 */
	{ 0,	0,	sys_getpid,		"getpid"		}, /* 20 */
	{ 5,	TF,	sys_mount,		"mount"			}, /* 21 */
	{ 1,	0,	sys_umount,		"oldumount"		}, /* 22 */
	{ 1,	0,	sys_setuid,		"setuid"		}, /* 23 */
	{ 0,	0,	sys_getuid,		"getuid"		}, /* 24 */
	{ 1,	0,	sys_stime,		"stime"			}, /* 25 */
	{ 4,	0,	sys_ptrace,		"ptrace"		}, /* 26 */
	{ 5,	0,	printargs,		"alarm"			}, /* 27 */
	{ 2,	0,	sys_fstat,		"oldfstat"		}, /* 28 */
	{ 0,	0,	printargs,		"pause"			}, /* 29 */
	{ 2,	0,	sys_utimes,		"utime"			}, /* 30 */
	{ 5,	0,	printargs,		"stty"			}, /* 31 */
	{ 5,	0,	printargs,		"gtty"			}, /* 32 */
	{ 2,	TF,	sys_access,		"access"		}, /* 33 */
	{ 5,	0,	printargs,		"nice"			}, /* 34 */
	{ 5,	0,	printargs,		"ftime"			}, /* 35 */
	{ 0,	0,	sys_sync,		"sync"			}, /* 36 */
	{ 2,	TS,	sys_kill,		"kill"			}, /* 37 */
	{ 2,	TF,	sys_rename,		"rename"		}, /* 38 */
	{ 2,	TF,	sys_mkdir,		"mkdir"			}, /* 39 */
	{ 1,	TF,	sys_rmdir,		"rmdir"			}, /* 40 */
	{ 1,	0,	sys_dup,		"dup"			}, /* 41 */
	{ 1,	0,	sys_pipe,		"pipe"			}, /* 42 */
	{ 1,	0,	sys_times,		"times"			}, /* 43 */
	{ 5,	0,	printargs,		"prof"			}, /* 44 */
	{ 1,	0,	sys_brk,		"brk"			}, /* 45 */
	{ 1,	0,	sys_setgid,		"setgid"		}, /* 46 */
	{ 0,	0,	printargs,		"getgid"		}, /* 47 */
	{ 5,	0,	printargs,		"signal"		}, /* 48 */
	{ 0,	0,	printargs,		"geteuid"		}, /* 49 */
	{ 0,	0,	printargs,		"getegid"		}, /* 50 */
	{ 1,	TF,	sys_acct,		"acct"			}, /* 51 */
	{ 2,	0,	sys_umount2,		"umount"		}, /* 52 */
	{ 5,	0,	printargs,		"lock"			}, /* 53 */
	{ 3,	0,	sys_ioctl,		"ioctl"			}, /* 54 */
	{ 3,	0,	sys_fcntl,		"fcntl"			}, /* 55 */
	{ 5,	0,	printargs,		"mpx"			}, /* 56 */
	{ 2,	0,	sys_setpgid,		"setpgid"		}, /* 57 */
	{ 2,	0,	printargs,		"ulimit"		}, /* 58 */
	{ 1,	0,	printargs,		"oldolduname"		}, /* 59 */
	{ 1,	0,	sys_umask,		"umask"			}, /* 60 */
	{ 1,	TF,	sys_chroot,		"chroot"		}, /* 61 */
	{ 2,	0,	sys_ustat,		"ustat"			}, /* 62 */
	{ 2,	0,	sys_dup2,		"dup2"			}, /* 63 */
	{ 0,	0,	printargs,		"getppid"		}, /* 64 */
	{ 0,	0,	sys_getpgrp,		"getpgrp"		}, /* 65 */
	{ 0,	0,	sys_setsid,		"setsid"		}, /* 66 */
	{ 3,	TS,	sys_sigaction,		"sigaction"		}, /* 67 */
	{ 5,	0,	printargs,		"sgetmask"		}, /* 68 */
	{ 5,	0,	printargs,		"ssetmask"		}, /* 69 */
	{ 2,	0,	sys_setreuid,		"setreuid"		}, /* 70 */
	{ 2,	0,	sys_setregid,		"setregid"		}, /* 71 */
	{ 3,	TS,	sys_sigsuspend,		"sigsuspend"		}, /* 72 */
	{ 1,	TS,	sys_sigpending,		"sigpending"		}, /* 73 */
	{ 2,	0,	sys_sethostname,	"sethostname"		}, /* 74 */
	{ 2,	0,	sys_setrlimit,		"setrlimit"		}, /* 75 */
	{ 2,	0,	sys_getrlimit,		"getrlimit"		}, /* 76 */
	{ 2,	0,	sys_getrusage,		"getrusage"		}, /* 77 */
	{ 2,	0,	sys_gettimeofday,	"gettimeofday"		}, /* 78 */
	{ 2,	0,	sys_settimeofday,	"settimeofday"		}, /* 79 */
	{ 2,	0,	sys_getgroups,		"getgroups"		}, /* 80 */
	{ 2,	0,	sys_setgroups,		"setgroups"		}, /* 81 */
	{ 5,	0,	sys_select,		"select"		}, /* 82 */
	{ 2,	TF,	sys_symlink,		"symlink"		}, /* 83 */
	{ 2,	TF,	sys_lstat,		"oldlstat"		}, /* 84 */
	{ 3,	TF,	sys_readlink,		"readlink"		}, /* 85 */
	{ 1,	0,	sys_uselib,		"uselib"		}, /* 86 */
	{ 1,	0,	sys_swapon,		"swapon"		}, /* 87 */
	{ 3,	0,	sys_reboot,		"reboot"		}, /* 88 */
	{ 3,	0,	sys_readdir,		"readdir"		}, /* 89 */
	{ 6,	0,	sys_mmap,		"mmap"			}, /* 90 */
	{ 2,	0,	sys_munmap,		"munmap"		}, /* 91 */
	{ 2,	TF,	sys_truncate,		"truncate"		}, /* 92 */
	{ 2,	0,	sys_ftruncate,		"ftruncate"		}, /* 93 */
	{ 2,	0,	sys_fchmod,		"fchmod"		}, /* 94 */
	{ 3,	0,	sys_fchown,		"fchown"		}, /* 95 */
	{ 2,	0,	sys_getpriority,	"getpriority"		}, /* 96 */
	{ 3,	0,	sys_setpriority,	"setpriority"		}, /* 97 */
	{ 5,	0,	printargs,		"profil"		}, /* 98 */
	{ 2,	TF,	sys_statfs,		"statfs"		}, /* 99 */
	{ 2,	0,	sys_fstatfs,		"fstatfs"		}, /* 100 */
	{ 5,	0,	printargs,		"ioperm"		}, /* 101 */
	{ 5,	0,	printargs,		"socketcall"		}, /* 102 */
	{ 3,	0,	sys_syslog,		"syslog"		}, /* 103 */
	{ 3,	0,	sys_setitimer,		"setitimer"		}, /* 104 */
	{ 2,	0,	sys_getitimer,		"getitimer"		}, /* 105 */
	{ 2,	TF,	sys_stat,		"stat"			}, /* 106 */
	{ 2,	TF,	sys_lstat,		"lstat"			}, /* 107 */
	{ 2,	0,	sys_fstat,		"fstat"			}, /* 108 */
	{ 1,	0,	printargs,		"olduname"		}, /* 109 */
	{ 1,	0,	sys_iopl,		"iopl"			}, /* 110 */
	{ 0,	0,	sys_vhangup,		"vhangup"		}, /* 111 */
	{ 0,	0,	sys_idle,		"idle"			}, /* 112 */
	{ 5,	0,	printargs,		"vm86"			}, /* 113 */
	{ 4,	TP,	sys_wait4,		"wait4"			}, /* 114 */
	{ 1,	0,	sys_swapoff,		"swapoff"		}, /* 115 */
	{ 1,	0,	sys_sysinfo,		"sysinfo"		}, /* 116 */
	{ 5,	0,	sys_ipc,		"ipc"			}, /* 117 */
	{ 1,	0,	sys_fsync,		"fsync"			}, /* 118 */
	{ 1,	TS,	sys_sigreturn,		"sigreturn"		}, /* 119 */
	{ 2,	TP,	sys_clone,		"clone"			}, /* 120 */
	{ 2,	0,	sys_setdomainname,	"setdomainname"		}, /* 121 */
	{ 1,	0,	sys_uname,		"uname"			}, /* 122 */
	{ 5,	0,	printargs,		"modify_ldt"		}, /* 123 */
	{ 1,	0,	sys_adjtimex,		"adjtimex"		}, /* 124 */
	{ 3,	0,	sys_mprotect,		"mprotect"		}, /* 125 */
	{ 3,	TS,	sys_sigprocmask,	"sigprocmask"		}, /* 126 */
	{ 2,	0,	sys_create_module,	"create_module"		}, /* 127 */
	{ 4,	0,	sys_init_module,	"init_module"		}, /* 128 */
	{ 1,	0,	sys_delete_module,	"delete_module"		}, /* 129 */
	{ 1,	0,	sys_get_kernel_syms,	"get_kernel_syms"	}, /* 130 */ 
	{ 4,	0,	sys_quotactl,		"quotactl"		}, /* 131 */
	{ 1,	0,	sys_getpgid,		"getpgid"		}, /* 132 */
	{ 1,	TF,	sys_fchdir,		"fchdir"		}, /* 133 */
	{ 0,	0,	sys_bdflush,		"bdflush"		}, /* 134 */
	{ 5,	0,	sys_sysfs,		"sysfs"			}, /* 135 */
	{ 1,	0,	sys_personality,	"personality"		}, /* 136 */
	{ 5,	0,	sys_afs_syscall,	"afs_syscall"		}, /* 137 */
	{ 1,	0,	sys_setfsuid,		"setfsuid"		}, /* 138 */
	{ 1,	0,	sys_setfsgid,		"setfsgid"		}, /* 139 */
	{ 5,	TF,	printargs,		"_llseek"		}, /* 140 */
	{ 3,	0,	sys_getdents,		"getdents"		}, /* 141 */
	{ 5,	0,	printargs,		"_newselect"		}, /* 142 */
	{ 2,	0,	sys_flock,		"flock"			}, /* 143 */
	{ 3,	0,	sys_msync,		"msync"			}, /* 144 */
	{ 3,	0,	sys_readv,		"readv"			}, /* 145 */
	{ 3,	0,	sys_writev,		"writev"		}, /* 146 */
	{ 1,	0,	sys_getsid,		"getsid"		}, /* 147 */
	{ 5,	0,	printargs,		"fdatasync"		}, /* 148 */
	{ 5,	0,	printargs,		"_sysctl"		}, /* 149 */
	{ 2,	0,	sys_mlock,		"mlock"			}, /* 150 */
	{ 2,	0,	sys_munlock,		"munlock"		}, /* 151 */
	{ 1,	0,	sys_mlockall,		"mlockall"		}, /* 152 */
	{ 0,	0,	sys_munlockall,		"munlockall"		}, /* 153 */
	{ 2,	0,	sys_sched_setparam,	"sched_setparam"	}, /* 154 */ 
	{ 2,	0,	sys_sched_getparam,	"sched_getparam"	}, /* 155 */ 
	{ 3,	0,	sys_sched_setscheduler,	"sched_setscheduler"	}, /* 156 */ 
	{ 2,	0,	sys_sched_getscheduler,	"sched_getscheduler"	}, /* 157 */ 
	{ 0,	0,	sys_sched_yield,	"sched_yield"		}, /* 158 */
	{ 5,	0,	printargs,		"SYS_159"		}, /* 159 */
	{ 5,	0,	printargs,		"SYS_160"		}, /* 160 */
	{ 5,	0,	printargs,		"SYS_161"		}, /* 161 */
	{ 2,	0,	sys_nanosleep,		"nanosleep"		}, /* 162 */
	{ 4,	0,	sys_mremap,		"mremap"		}, /* 163 */
	{ 3,	0,	sys_setresuid,		"setresuid"		}, /* 164 */
	{ 3,	0,	sys_setresuid,		"getresuid"		}, /* 165 */
	{ 5,	0,	sys_query_module,	"query_module"		}, /* 166 */
	{ 3,	0,	sys_poll,		"poll"			}, /* 167 */
	{ 5,	0,	printargs,		"nfsservctl"		}, /* 168 */
	{ 3,	0,	sys_setresgid,		"setresgid"		}, /* 169 */
	{ 3,	0,	sys_setresgid,		"getresgid"		}, /* 170 */
	{ 5,	0,	printargs,		"prctl"			}, /* 171 */
	{ 1,	TS,	printargs,		"rt_sigreturn"		}, /* 172 */
	{ 4,	TS,	sys_rt_sigaction,	"rt_sigaction"		}, /* 173 */
	{ 4,	TS,	sys_rt_sigprocmask,	"rt_sigprocmask"	}, /* 174 */ 
	{ 2,	TS,	sys_rt_sigpending,	"rt_sigpending"		}, /* 175 */
	{ 4,	TS,	sys_rt_sigtimedwait,	"rt_sigtimedwait"	}, /* 176 */ 
	{ 3,	TS,	sys_rt_sigqueueinfo,	"rt_sigqueueinfo"	}, /* 177 */ 
	{ 2,	TS,	sys_rt_sigsuspend,	"rt_sigsuspend"		}, /* 178 */
	{ 5,	TF,	sys_pread,		"pread"			}, /* 179 */
	{ 5,	TF,	sys_pwrite,		"pwrite"		}, /* 180 */
	{ 3,	TF,	sys_chown,		"chown"			}, /* 181 */
	{ 2,	0,	sys_getcwd,		"getcwd"		}, /* 182 */
	{ 2,	0,	sys_capget,		"capget"		}, /* 183 */
	{ 2,	0,	sys_capset,		"capset"		}, /* 184 */
	{ 2,	TS,	sys_sigaltstack,	"sigaltstack"		}, /* 185 */
	{ 4,	TF,	sys_sendfile,		"sendfile"		}, /* 186 */
	{ 5,	0,	printargs,		"getpmsg"		}, /* 187 */
	{ 5,	0,	printargs,		"putpmsg"		}, /* 188 */
	{ 0,	TP,	sys_vfork,		"vfork"			}, /* 189 */
	{ -1,	0,	printargs,		"SYS_190"		}, /* 190 */
	{ 2,	0,	printargs,		"ugetrlimit"		}, /* 191 */
	{ 8,	0,	sys_mmap,		"mmap2"			}, /* 192 */
	{ 4,	TF,	printargs,		"truncate64"		}, /* 193 */
	{ 4,	TF,	printargs,		"ftruncate64"		}, /* 194 */
	{ 2,	TF,	sys_stat64,		"stat64"		}, /* 195 */
	{ 2,	TF,	sys_lstat64,		"lstat64"		}, /* 196 */
	{ 2,	TF,	sys_fstat64,		"fstat64"		}, /* 197 */
	{ 5,	0,	printargs,		"pciconfig_read"	}, /* 198 */
	{ 5,	0,	printargs,		"pciconfig_write"	}, /* 199 */
	{ 3,	0,	printargs,		"pciconfig_iobase"	}, /* 200 */
	{ 8,	0,	printargs,		"MOL"			}, /* 201 */
	{ 3,	0,	printargs,		"getdents64"		}, /* 202 */
	{ 2,	0,	sys_pivotroot,		"pivot_root"		}, /* 203 */
	{ 3,	0,	sys_fcntl,		"fcntl64"		}, /* 204 */
	{ 3,	0,	sys_madvise,		"madvise"		}, /* 205 */
	{ 3,	0,	printargs,		"mincore"		}, /* 206 */
	{ 5,	0,	printargs,		"SYS_207"		}, /* 207 */
	{ 5,	0,	printargs,		"SYS_208"		}, /* 208 */
	{ 5,	0,	printargs,		"SYS_209"		}, /* 209 */
	{ 5,	0,	printargs,		"SYS_210"		}, /* 210 */
	{ 5,	0,	printargs,		"SYS_211"		}, /* 211 */
	{ 5,	0,	printargs,		"SYS_212"		}, /* 212 */
	{ 5,	0,	printargs,		"SYS_213"		}, /* 213 */
	{ 5,	0,	printargs,		"SYS_214"		}, /* 214 */
	{ 5,	0,	printargs,		"SYS_215"		}, /* 215 */
	{ 5,	0,	printargs,		"SYS_216"		}, /* 216 */
	{ 5,	0,	printargs,		"SYS_217"		}, /* 217 */
	{ 5,	0,	printargs,		"SYS_218"		}, /* 218 */
	{ 5,	0,	printargs,		"SYS_219"		}, /* 219 */
	{ 5,	0,	printargs,		"SYS_220"		}, /* 220 */
	{ 5,	0,	printargs,		"SYS_221"		}, /* 221 */
	{ 5,	0,	printargs,		"SYS_222"		}, /* 222 */
	{ 5,	0,	printargs,		"SYS_223"		}, /* 223 */
	{ 5,	0,	printargs,		"SYS_224"		}, /* 224 */
	{ 5,	0,	printargs,		"SYS_225"		}, /* 225 */
	{ 5,	0,	printargs,		"SYS_226"		}, /* 226 */
	{ 5,	0,	printargs,		"SYS_227"		}, /* 227 */
	{ 5,	0,	printargs,		"SYS_228"		}, /* 228 */
	{ 5,	0,	printargs,		"SYS_229"		}, /* 229 */
	{ 5,	0,	printargs,		"SYS_230"		}, /* 230 */
	{ 5,	0,	printargs,		"SYS_231"		}, /* 231 */
	{ 5,	0,	printargs,		"SYS_232"		}, /* 232 */
	{ 5,	0,	printargs,		"SYS_233"		}, /* 233 */
	{ 5,	0,	printargs,		"SYS_234"		}, /* 234 */
	{ 5,	0,	printargs,		"SYS_235"		}, /* 235 */
	{ 5,	0,	printargs,		"SYS_236"		}, /* 236 */
	{ 5,	0,	printargs,		"SYS_237"		}, /* 237 */
	{ 5,	0,	printargs,		"SYS_238"		}, /* 238 */
	{ 5,	0,	printargs,		"SYS_239"		}, /* 239 */
	{ 5,	0,	printargs,		"SYS_240"		}, /* 240 */
	{ 5,	0,	printargs,		"SYS_241"		}, /* 241 */
	{ 5,	0,	printargs,		"SYS_242"		}, /* 242 */
	{ 5,	0,	printargs,		"SYS_243"		}, /* 243 */
	{ 5,	0,	printargs,		"SYS_244"		}, /* 244 */
	{ 5,	0,	printargs,		"SYS_245"		}, /* 245 */
	{ 5,	0,	printargs,		"SYS_246"		}, /* 246 */
	{ 5,	0,	printargs,		"SYS_247"		}, /* 247 */
	{ 5,	0,	printargs,		"SYS_248"		}, /* 248 */
	{ 5,	0,	printargs,		"SYS_249"		}, /* 249 */
	{ 5,	0,	printargs,		"SYS_250"		}, /* 250 */
	{ 5,	0,	printargs,		"SYS_251"		}, /* 251 */
	{ 5,	0,	printargs,		"SYS_252"		}, /* 252 */
	{ 5,	0,	printargs,		"SYS_253"		}, /* 253 */
	{ 5,	0,	printargs,		"SYS_254"		}, /* 254 */
	{ 5,	0,	printargs,		"SYS_255"		}, /* 255 */

	{ 8,	0,	printargs,		"socket_subcall"}, /* 256 */
	{ 3,	TN,	sys_socket,		"socket"	}, /* 257 */
	{ 3,	TN,	sys_bind,		"bind"		}, /* 258 */
	{ 3,	TN,	sys_connect,		"connect"	}, /* 259 */
	{ 2,	TN,	sys_listen,		"listen"	}, /* 260  */
	{ 3,	TN,	sys_accept,		"accept"	}, /* 261 */
	{ 3,	TN,	sys_getsockname,	"getsockname"	}, /* 262 */
	{ 3,	TN,	sys_getpeername,	"getpeername"	}, /* 263 */
	{ 4,	TN,	sys_socketpair,		"socketpair"	}, /* 264 */
	{ 4,	TN,	sys_send,		"send"		}, /* 265 */
	{ 4,	TN,	sys_recv,		"recv"		}, /* 266 */
	{ 6,	TN,	sys_sendto,		"sendto"	}, /* 267 */
	{ 6,	TN,	sys_recvfrom,		"recvfrom"	}, /* 268 */
	{ 2,	TN,	sys_shutdown,		"shutdown"	}, /* 269 */
	{ 5,	TN,	sys_setsockopt,		"setsockopt"	}, /* 270 */
	{ 5,	TN,	sys_getsockopt,		"getsockopt"	}, /* 271 */
	{ 5,	TN,	sys_sendmsg,		"sendmsg"	}, /* 272 */
	{ 5,	TN,	sys_recvmsg,		"recvmsg"	}, /* 273 */
	{ 5,	0,	printargs,		"SYS_274"	}, /* 274 */
	{ 5,	0,	printargs,		"SYS_275"	}, /* 275 */

	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 276 */
	{ 4,	TI,	printargs,		"semop"		}, /* 277 */
	{ 4,	TI,	sys_semget,		"semget"	}, /* 278 */
	{ 4,	TI,	sys_semctl,		"semctl"	}, /* 279 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 280 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 281 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 282 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 283 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 284 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 285 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 286 */
	{ 4,	TI,	sys_msgsnd,		"msgsnd"	}, /* 287 */
	{ 4,	TI,	sys_msgrcv,		"msgrcv"	}, /* 288 */
	{ 4,	TI,	sys_msgget,		"msgget"	}, /* 289 */
	{ 4,	TI,	sys_msgctl,		"msgctl"	}, /* 290 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 291 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 292 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 293 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 294 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 295 */
	{ 4,	0,	printargs,		"ipc_subcall"	}, /* 296 */
	{ 4,	TI,	sys_shmat,		"shmat"		}, /* 297 */
	{ 4,	TI,	sys_shmdt,		"shmdt"		}, /* 298 */
	{ 4,	TI,	sys_shmget,		"shmget"	}, /* 299 */
	{ 4,	TI,	sys_shmctl,		"shmctl"	}, /* 300 */
	{ 5,	0,	printargs,		"SYS_301"	}, /* 301 */
	{ 5,	0,	printargs,		"SYS_302"	}, /* 302 */
	{ 5,	0,	printargs,		"SYS_303"	}, /* 303 */
	{ 5,	0,	printargs,		"SYS_304"	}, /* 304 */
	{ 5,	0,	printargs,		"SYS_305"	}, /* 305 */
