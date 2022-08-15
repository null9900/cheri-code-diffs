/*
    IMPORTANT: This file has been compiled using this flag: -Xclang -cheri-bounds=subobject-safe
 */
#include <stdio.h>
#include <stdlib.h>

#define ID_LENGTH 8

struct user {
  char user_id[ID_LENGTH];
  // should be 0 for non admin users
  int admin;
} __subobject_use_container_bounds u;

char get_random_char(){
  return 'A' + (random() % 26);
}

void
create_non_admin_user()
{
  u.admin = 0;
  for(size_t i = 0; i <= ID_LENGTH; i++){
    u.user_id[i] = get_random_char();
  }
}

int
main(void)
{
  create_non_admin_user();
  if(u.admin != 0){
      printf("user should not be admin!");
      exit(1);
  }
  return 0;
}

