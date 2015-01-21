
#ifndef _SIMULATION_H_
	#define _SIMULATION_H_
#endif

#ifndef _TYPES_H_
	#include "types.h"
#endif

typedef enum{
	raw = 0,
	tcp = 1,
} simulation_socket_type;

typedef UInt8 simulation_addr[4];

//only necessary for tcp connections. raw sockets dont have ports.
Int simulation_bind(Pointer socket,Int port);
Int simulation_listen(Pointer socket);
Pointer simulation_connect(simulation_addr addr);
//after socket has been bound and is set to listen state, use this to accept incoming connections.
Pointer simulation_accept(Pointer socket);
//use this to create the socket.
Pointer simulation_socket(simulation_socket_type type);

Int simulation_read_socket(Pointer socket,Int8* data, Int size);
Int simulation_write_socket(Pointer socket, Int8* data, Int size);

/*
 *
 * PUBLIC PARTION, MAYBE WRITE ANOTHER HEADER FILE FOR IT.
 *
 */

typedef struct{
	simulation_addr gateway;
	simulation_addr local_subnet;
} network_area;

void simulation_create_network(network_area network);
void simulation_add_peer_to_network(network_area network, Pointer peer);
Pointer simulation_get_peer_list(network_area network);

void simulation_start(void);
void simulation_stop(void);
