BEGIN {
  inheader=0;
#  use_ldap_define = 0;
  current_file="";
  print "#ifndef _PROTO_H_"
  print "#define _PROTO_H_"
  print "/* This file is automatically generated with \"make proto\". DO NOT EDIT */"
  print ""
}

END {
  print "#endif /* _PROTO_H_ */"
}

{
  if (FILENAME!=current_file) {
#    if (use_ldap_define)
#    {
#      print "#endif /* USE_LDAP */"
#      use_ldap_define = 0;
#    }
    print ""
    print "/*The following definitions come from ",FILENAME," */"
    print ""
    current_file=FILENAME
#    if (current_file=="ldap.c") {
#      print "#ifdef USE_LDAP"
#      use_ldap_define = 1;
#    }
  }
  if (inheader) {
    if (match($0,"[)][ \t]*$")) {
      inheader = 0;
      printf "%s;\n",$0;
    } else {
      printf "%s\n",$0;
    }
    next;
  }
}

# we handle the loadparm.c fns separately

/^FN_LOCAL_BOOL/ {
  split($0,a,"[,()]")
  printf "BOOL %s(int );\n", a[2]
}

/^FN_LOCAL_STRING/ {
  split($0,a,"[,()]")
  printf "char *%s(int );\n", a[2]
}

/^FN_LOCAL_INT/ {
  split($0,a,"[,()]")
  printf "int %s(int );\n", a[2]
}

/^FN_LOCAL_CHAR/ {
  split($0,a,"[,()]")
  printf "char %s(int );\n", a[2]
}

/^FN_GLOBAL_BOOL/ {
  split($0,a,"[,()]")
  printf "BOOL %s(void);\n", a[2]
}

/^FN_GLOBAL_STRING/ {
  split($0,a,"[,()]")
  printf "char *%s(void);\n", a[2]
}

/^FN_GLOBAL_INT/ {
  split($0,a,"[,()]")
  printf "int %s(void);\n", a[2]
}

/^static|^extern/ || !/^[a-zA-Z]/ || /[;]/ {
  next;
}

#
# We have to split up the start
# matching as we now have so many start
# types that it can cause some versions
# of nawk/awk to choke and fail on
# the full match. JRA.
#

{
  gotstart = 0;
  if( $0 ~ /^connection_struct|^pipes_struct|^file_fd_struct|^files_struct|^connection_struct|^uid_t|^gid_t|^unsigned|^mode_t|^DIR|^user|^int|^pid_t|^ino_t|^off_t/ ) {
    gotstart = 1;
  }

  if( $0 ~ /^LOCAL_GRP|^DOMAIN_GRP|^SMB_STRUCT_DIRENT|^SEC_ACL|^SEC_DESC|^SEC_DESC_BUF|^DOM_SID|^smb_ucs2_t/ ) {
    gotstart = 1;
  }

  if( $0 ~ /^TDB_CONTEXT|^TDB_DATA|^smb_ucs2_t|^TALLOC_CTX|^hash_element/ ) {
    gotstart = 1;
  }

  if( $0 ~ /^long|^char|^uint|^struct|^BOOL|^void|^time|^smb_shm_offset_t|^shm_offset_t|^enum remote_arch_types|^FILE|^SMB_OFF_T|^size_t|^ssize_t|^SMB_BIG_UINT/ ) {
    gotstart = 1;
  }
  if(!gotstart) {
    next;
  }
}


/[(].*[)][ \t]*$/ {
    printf "%s;\n",$0;
    next;
}

/[(]/ {
  inheader=1;
  printf "%s\n",$0;
  next;
}

