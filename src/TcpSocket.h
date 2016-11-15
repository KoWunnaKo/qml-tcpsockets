/*
 * Copyright (C) 2016 EPFL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

/**
 * @file TcpSocket.h
 * @brief QML wrapper header for QTcpSocket
 * @author Ayberk Özgür
 * @date 2016-11-10
 */

#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QQuickItem>
#include <QTcpSocket>
#include <QList>

#include "QIntPtr.h"

class TcpSocket : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

public:

    /**
     * @brief Creates a new TcpSocket with the given QML parent
     *
     * @param parent The QML parent
     */
    TcpSocket(QQuickItem* parent = 0);

    /**
     * @brief Creates a new TcpSocket with the given QML parent, calls socketDescriptor->deleteLater()
     *
     * @param socketDescriptor Descriptor to the external native socket that was opened outside this wrapper, calls deleteLater() on it in the end
     * @param parent The QML parent
     */
    TcpSocket(QIntPtr* socketDescriptor, QQuickItem* parent = 0);

    /**
     * @brief Destroys this TcpSocket
     */
    ~TcpSocket();

public slots:

    /**
     * @brief Writes bytes over the socket
     *
     * @param bytes Bytes to write, all must be within [0x00,0xFF]
     * @return Whether all bytes were successfully written
     */
    bool writeBytes(QList<int> bytes);

    /**
     * @brief Initializes the socket with the given native descriptor (returned from TcpServer), calls socketDescriptor->deleteLater() in the end
     *
     * @param socketDescriptor Native socket descriptor, calls deleterLater() on it in the end
     */
    void setSocketDescriptor(QIntPtr* socketDescriptor);












    void conn(QString host, int port);







signals:

    /**
     * @brief Emitted when the socket is connected
     */
    void connected();

    /**
     * @brief Emitted when the socket is disconected
     */
    void disconnected();

    /**
     * @brief Emitted when some bytes are received
     *
     * @param message Byte array that was received, all elements are guaranteed to be in [0x00, 0xFF]
     */
    void bytesReceived(QList<int> bytes);

public slots:

    /**
     * @brief Publishes all available received bytes via bytesReceived(QVariant)
     */
    void publish();

private:

    QTcpSocket socket;  ///< The low level socket

};

Q_DECLARE_METATYPE(TcpSocket*)

#endif /* TCPSOCKET_H */
