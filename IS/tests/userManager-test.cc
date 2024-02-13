#include "userManager.h"
#include "programa.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::StartsWith;

TEST(userManagerTest, Login)
{
    UserManager usm;
    Programa pr;
    pr.inicioProgramaUsuarios();
    EXPECT_EQ(usm.login("i22lofis", "TOcoTon"),true);
    EXPECT_EQ(usm.login("i 22lofis", "TocoTon"),false);
}


TEST(DarseDeBajaTest, UsuarioValido) {
    UserManager userManager;
    EXPECT_TRUE(userManager.iniciarSesion("usuario", "contraseña"));

    // Simulamos el flujo de darse de baja
    EXPECT_TRUE(userManager.darseDeBaja());
}

TEST(DarseDeBajaTest, UsuarioInvalido) {
    UserManager userManager;
    EXPECT_FALSE(userManager.iniciarSesion("usuario_invalido", "contraseña"));

    // Como el usuario es inválido, no se debería permitir darse de baja
    EXPECT_FALSE(userManager.darseDeBaja());
}

TEST(DarseDeBajaTest, ConfirmacionUsuario) {
    UserManager userManager;
    EXPECT_TRUE(userManager.iniciarSesion("usuario", "contraseña"));

    // Simulamos la confirmación del usuario para darse de baja
    EXPECT_TRUE(userManager.darseDeBaja());
}

TEST(DarseDeBajaTest, NotificacionExitosa) {
    UserManager userManager;
    EXPECT_TRUE(userManager.iniciarSesion("usuario", "contraseña"));

    // Simulamos la confirmación del usuario para darse de baja
    EXPECT_TRUE(userManager.darseDeBaja());

    // Verificamos que se notifique una eliminación exitosa
    // En este ejemplo, suponemos que la notificación se realiza a través de una función miembro de UserManager
    EXPECT_TRUE(userManager.notificarEliminacionExitosa());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
