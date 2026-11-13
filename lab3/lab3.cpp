
#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int rank, size;
    int data;
    MPI_Status status;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 3)
    {
        if (rank == 0)
            printf("Please run with 3 processes!\n");

        MPI_Finalize();
        return 1;
    }

    if (rank == 0)
    {
        MPI_Recv(&data, 1, MPI_INT, 2, 0,
            MPI_COMM_WORLD, &status);
        printf("Process 1 received %d from Process 3\n", data);

        MPI_Recv(&data, 1, MPI_INT, 1, 0,
            MPI_COMM_WORLD, &status);
        printf("Process 1 received %d from Process 2\n", data);

        data = 400;
        MPI_Send(&data, 1, MPI_INT, 2, 0,
            MPI_COMM_WORLD);
        printf("Process 1 sent %d to Process 3\n", data);
    }

    else if (rank == 1)
    {
        MPI_Recv(&data, 1, MPI_INT, 2, 0,
            MPI_COMM_WORLD, &status);
        printf("Process 2 received %d from Process 3\n", data);

        data = 300;
        MPI_Send(&data, 1, MPI_INT, 0, 0,
            MPI_COMM_WORLD);
        printf("Process 2 sent %d to Process 1\n", data);
    }

    else if (rank == 2)
    {
        data = 100;
        MPI_Send(&data, 1, MPI_INT, 1, 0,
            MPI_COMM_WORLD);
        printf("Process 3 sent %d to Process 2\n", data);

        data = 200;
        MPI_Send(&data, 1, MPI_INT, 0, 0,
            MPI_COMM_WORLD);
        printf("Process 3 sent %d to Process 1\n", data);

        MPI_Recv(&data, 1, MPI_INT, 0, 0,
            MPI_COMM_WORLD, &status);
        printf("Process 3 received %d from Process 1\n", data);
    }

    MPI_Finalize();
    return 0;
}
